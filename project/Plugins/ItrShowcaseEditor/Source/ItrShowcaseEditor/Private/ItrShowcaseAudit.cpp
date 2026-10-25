// ITR Showcase: T-116 asset audit helpers. See ItrShowcaseAudit.h and tools/itr-showcase/audit/README.md.
#include "ItrShowcaseAudit.h"

#include "AssetRegistryModule.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshSocket.h"
#include "Engine/Texture2D.h"
#include "Engine/TextureCube.h"
#include "Engine/TextureLODSettings.h"
#include "HAL/PlatformProcess.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Interfaces/ITargetPlatform.h"
#include "Interfaces/ITargetPlatformManagerModule.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialLayersFunctions.h"
#include "StaticParameterSet.h"
#include "Materials/MaterialExpression.h"
#include "Misc/FileHelper.h"
#include "Misc/PackageName.h"
#include "Misc/Paths.h"
#include "Misc/SecureHash.h"
#include "UObject/MetaData.h"
#include "Modules/ModuleManager.h"
#include "AI/Navigation/NavCollisionBase.h"
#include "PhysicsEngine/BodySetup.h"
#include "Particles/ParticleSystem.h"
#include "Kismet2/StructureEditorUtils.h"
#include "UserDefinedStructure/UserDefinedStructEditorData.h"
#include "Engine/UserDefinedStruct.h"
#include "EdGraphSchema_K2.h"
#include "Particles/ParticleEmitter.h"
#include "Particles/ParticleLODLevel.h"
#include "Particles/ParticleModule.h"
#include "Particles/ParticleModuleRequired.h"
#include "Particles/Spawn/ParticleModuleSpawn.h"
#include "Particles/TypeData/ParticleModuleTypeDataGpu.h"
#include "Distributions/DistributionFloatConstant.h"
#include "Distributions/DistributionFloatConstantCurve.h"
#include "Distributions/DistributionFloatUniform.h"
#include "Distributions/DistributionVectorConstant.h"
#include "Distributions/DistributionVectorConstantCurve.h"
#include "Distributions/DistributionVectorUniform.h"
#include "Sound/SoundCue.h"
#include "Sound/SoundNode.h"
#include "Policies/CondensedJsonPrintPolicy.h"
#include "RHI.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "StaticMeshResources.h"
#include "UObject/Package.h"
#include "UObject/MetaData.h"
#include "UObject/UObjectIterator.h"

DEFINE_LOG_CATEGORY_STATIC(LogItrAudit, Log, All);

// ItrShowcaseBPGen.cpp: the generator's spec type parser ("int", "struct:/Game/X.X[]" ...)
bool ItrBPGenParsePinType(const FString& Type, FEdGraphPinType& Out, FString& Error);
// ItrShowcaseBPGen.cpp: the generator's JSON -> property converter
bool ItrBPGenApplyJsonProp(UObject* Obj, const FString& Key, const TSharedPtr<FJsonValue>& Val, TArray<FString>& OutProblems);

namespace ItrAudit
{
static TSharedPtr<FJsonObject> ParseObj(const FString& S, TArray<FString>& Problems, const TCHAR* What)
{
	TSharedPtr<FJsonObject> O;
	if (S.IsEmpty()) return MakeShared<FJsonObject>();
	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(S), O) || !O.IsValid()) { Problems.Add(FString::Printf(TEXT("%s: invalid JSON"), What)); return nullptr; }
	return O;
}

static FString Join(const TArray<FString>& L) { return FString::Join(L, TEXT("\n")); }

static void ApplyAll(UObject* Obj, const TSharedPtr<FJsonObject>& Props, const TSet<FString>& Skip, TArray<FString>& Problems)
{
	if (!Obj || !Props.IsValid()) return;
	for (const auto& KV : Props->Values)
	{
		if (Skip.Contains(KV.Key)) continue;
		ItrBPGenApplyJsonProp(Obj, KV.Key, KV.Value, Problems);
	}
}

// back to class defaults (every property except instanced subobjects), so that a rebuild in place does not keep values of an earlier run
static void ResetToDefaults(UObject* Obj)
{
	UObject* Def = Obj->GetClass()->GetDefaultObject();
	for (TFieldIterator<FProperty> It(Obj->GetClass()); It; ++It)
	{
		FProperty* P = *It;
		if (P->HasAnyPropertyFlags(CPF_Transient | CPF_InstancedReference | CPF_ContainsInstancedReference | CPF_PersistentInstance)) continue;
		if (FStructProperty* SP = CastField<FStructProperty>(P)) if (SP->Struct == TBaseStructure<FGuid>::Get()) continue;   // identity GUIDs stay
		P->CopyCompleteValue_InContainer(Obj, Def);
	}
}

static UObject* FindOrCreateAsset(const FString& AssetPath, UClass* Cls, TArray<FString>& Problems, bool& bCreated)
{
	bCreated = false;
	if (!FPackageName::IsValidLongPackageName(AssetPath)) { Problems.Add(FString::Printf(TEXT("invalid asset path %s"), *AssetPath)); return nullptr; }
	const FString Name = FPackageName::GetLongPackageAssetName(AssetPath);
	UObject* Existing = LoadObject<UObject>(nullptr, *(AssetPath + TEXT(".") + Name), nullptr, LOAD_NoWarn | LOAD_Quiet);
	if (Existing)
	{
		if (Existing->GetClass() != Cls) { Problems.Add(FString::Printf(TEXT("%s exists with class %s, wanted %s"), *AssetPath, *Existing->GetClass()->GetName(), *Cls->GetName())); return nullptr; }
		return Existing;
	}
	UPackage* Pkg = CreatePackage(*AssetPath);
	Pkg->FullyLoad();
	UObject* O = NewObject<UObject>(Pkg, Cls, *Name, RF_Public | RF_Standalone | RF_Transactional);
	FAssetRegistryModule::AssetCreated(O);
	bCreated = true;
	return O;
}

static UClass* FindClassByName(const FString& Name)
{
	if (Name.StartsWith(TEXT("/"))) return LoadObject<UClass>(nullptr, *Name, nullptr, LOAD_NoWarn | LOAD_Quiet);
	if (UClass* C = FindObject<UClass>(ANY_PACKAGE, *Name)) return C;
	return nullptr;
}

// ---------------------------------------------------------------- dump (cooked-data shape)
static TSharedPtr<FJsonObject> StructJson(const UStruct* S, const void* Data, const void* Def, int32 Depth);

static TSharedPtr<FJsonValue> PropValue(FProperty* P, const void* V, const void* Def, int32 Depth)
{
	if (Depth > 24) return MakeShared<FJsonValueString>(TEXT("(too deep)"));
	if (FBoolProperty* B = CastField<FBoolProperty>(P)) return MakeShared<FJsonValueBoolean>(B->GetPropertyValue(V));
	if (FEnumProperty* E = CastField<FEnumProperty>(P))
	{
		const int64 X = E->GetUnderlyingProperty()->GetSignedIntPropertyValue(V);
		return MakeShared<FJsonValueString>(E->GetEnum()->GetNameStringByValue(X));
	}
	if (FByteProperty* BP = CastField<FByteProperty>(P))
	{
		const uint8 X = BP->GetPropertyValue(V);
		if (BP->Enum) return MakeShared<FJsonValueString>(BP->Enum->GetNameStringByValue(X));
		return MakeShared<FJsonValueNumber>(X);
	}
	if (FNumericProperty* N = CastField<FNumericProperty>(P))
	{
		if (N->IsFloatingPoint()) return MakeShared<FJsonValueNumber>(N->GetFloatingPointPropertyValue(V));
		return MakeShared<FJsonValueNumber>((double)N->GetSignedIntPropertyValue(V));
	}
	if (FStrProperty* SP = CastField<FStrProperty>(P)) return MakeShared<FJsonValueString>(SP->GetPropertyValue(V));
	if (FNameProperty* NP = CastField<FNameProperty>(P)) return MakeShared<FJsonValueString>(NP->GetPropertyValue(V).ToString());
	if (FTextProperty* TP = CastField<FTextProperty>(P)) return MakeShared<FJsonValueString>(TP->GetPropertyValue(V).ToString());
	if (FSoftObjectProperty* SO = CastField<FSoftObjectProperty>(P))
	{
		const FSoftObjectPtr& Ptr = *(const FSoftObjectPtr*)V;
		return Ptr.IsNull() ? MakeShared<FJsonValueNull>() : (TSharedPtr<FJsonValue>)MakeShared<FJsonValueString>(Ptr.ToSoftObjectPath().ToString());
	}
	if (FObjectPropertyBase* OP = CastField<FObjectPropertyBase>(P))
	{
		UObject* O = OP->GetObjectPropertyValue(V);
		return O ? (TSharedPtr<FJsonValue>)MakeShared<FJsonValueString>(O->GetPathName()) : MakeShared<FJsonValueNull>();
	}
	if (FStructProperty* St = CastField<FStructProperty>(P)) return MakeShared<FJsonValueObject>(StructJson(St->Struct, V, Def, Depth + 1));
	if (FArrayProperty* AP = CastField<FArrayProperty>(P))
	{
		FScriptArrayHelper H(AP, V);
		TArray<TSharedPtr<FJsonValue>> Items;
		for (int32 i = 0; i < H.Num(); ++i) Items.Add(PropValue(AP->Inner, H.GetRawPtr(i), nullptr, Depth + 1));   // array elements: full (as cooked)
		return MakeShared<FJsonValueArray>(Items);
	}
	if (FSetProperty* SetP = CastField<FSetProperty>(P))
	{
		FScriptSetHelper H(SetP, V);
		TArray<TSharedPtr<FJsonValue>> Items;
		for (int32 i = 0; i < H.GetMaxIndex(); ++i) if (H.IsValidIndex(i)) Items.Add(PropValue(SetP->ElementProp, H.GetElementPtr(i), nullptr, Depth + 1));
		return MakeShared<FJsonValueArray>(Items);
	}
	if (FMapProperty* MP = CastField<FMapProperty>(P))
	{
		FScriptMapHelper H(MP, V);
		TArray<TSharedPtr<FJsonValue>> Items;
		for (int32 i = 0; i < H.GetMaxIndex(); ++i)
		{
			if (!H.IsValidIndex(i)) continue;
			TSharedRef<FJsonObject> E = MakeShared<FJsonObject>();
			E->SetField(TEXT("Key"), PropValue(MP->KeyProp, H.GetKeyPtr(i), nullptr, Depth + 1));
			E->SetField(TEXT("Value"), PropValue(MP->ValueProp, H.GetValuePtr(i), nullptr, Depth + 1));
			Items.Add(MakeShared<FJsonValueObject>(E));
		}
		return MakeShared<FJsonValueArray>(Items);
	}
	FString Text;
	P->ExportTextItem(Text, V, nullptr, nullptr, PPF_None);
	return MakeShared<FJsonValueString>(TEXT("(") + P->GetClass()->GetName() + TEXT(") ") + Text);
}

// every serialized property (also editor-only ones, listed in "__eo"); "__nd" = keys whose value differs from Def (the archetype / the
// enclosing default), present only when Def is given. Static array elements are "Name", "Name[1]", ... like CUE4Parse prints them.
static TSharedPtr<FJsonObject> StructJson(const UStruct* S, const void* Data, const void* Def, int32 Depth)
{
	TSharedPtr<FJsonObject> O = MakeShared<FJsonObject>();
	TArray<TSharedPtr<FJsonValue>> ND, EO;
	for (TFieldIterator<FProperty> It(S); It; ++It)
	{
		FProperty* P = *It;
		if (P->HasAnyPropertyFlags(CPF_Transient | CPF_Deprecated | CPF_SkipSerialization)) continue;
		for (int32 i = 0; i < P->ArrayDim; ++i)
		{
			const void* V = P->ContainerPtrToValuePtr<void>(Data, i);
			const void* D = Def ? P->ContainerPtrToValuePtr<void>(Def, i) : nullptr;
			const FString Key = i == 0 ? P->GetName() : FString::Printf(TEXT("%s[%d]"), *P->GetName(), i);
			O->SetField(Key, PropValue(P, V, D, Depth));
			if (D && !P->Identical(V, D, PPF_None)) ND.Add(MakeShared<FJsonValueString>(Key));
			if (P->HasAnyPropertyFlags(CPF_EditorOnly)) EO.Add(MakeShared<FJsonValueString>(Key));
		}
	}
	if (Def) O->SetArrayField(TEXT("__nd"), ND);
	if (EO.Num()) O->SetArrayField(TEXT("__eo"), EO);
	return O;
}

static TSharedPtr<FJsonObject> ObjectJson(UObject* Obj)
{
	if (!Obj) return nullptr;
	UObject* Arch = Obj->GetArchetype();
	TSharedPtr<FJsonObject> O = StructJson(Obj->GetClass(), Obj, Arch, 0);
	O->SetStringField(TEXT("__class"), Obj->GetClass()->GetPathName());
	O->SetStringField(TEXT("__path"), Obj->GetPathName());
	return O;
}

static FString Sha1Hex(const uint8* Data, int64 Size)
{
	uint8 H[20];
	FSHA1::HashBuffer(Data, (uint64)Size, H);
	return BytesToHex(H, 20).ToLower();
}

static TSharedPtr<FJsonValue> NumArr(std::initializer_list<double> L)
{
	TArray<TSharedPtr<FJsonValue>> A;
	for (double D : L) A.Add(MakeShared<FJsonValueNumber>(D));
	return MakeShared<FJsonValueArray>(A);
}

static void TextureFacts(UTexture* T, TSharedPtr<FJsonObject> F, TArray<FString>& Problems)
{
	TSharedRef<FJsonObject> Src = MakeShared<FJsonObject>();
	Src->SetNumberField(TEXT("sizeX"), T->Source.GetSizeX());
	Src->SetNumberField(TEXT("sizeY"), T->Source.GetSizeY());
	Src->SetNumberField(TEXT("mips"), T->Source.GetNumMips());
	Src->SetNumberField(TEXT("slices"), T->Source.GetNumSlices());
	Src->SetStringField(TEXT("format"), StaticEnum<ETextureSourceFormat>()->GetNameStringByValue((int64)T->Source.GetFormat()));
	TArray64<uint8> Mip;
	if (T->Source.IsValid() && T->Source.GetMipData(Mip, 0)) Src->SetStringField(TEXT("sha1"), Sha1Hex(Mip.GetData(), Mip.Num()));
	else Problems.Add(TEXT("texture source has no mip 0 data"));
	F->SetObjectField(TEXT("source"), Src);

	// what the cooker makes of it for Windows (the game's platform): the format / size / mip count to compare with the cooked game texture
	ITargetPlatform* TP = GetTargetPlatformManagerRef().FindTargetPlatform(TEXT("WindowsNoEditor"));
	if (!TP) { Problems.Add(TEXT("target platform WindowsNoEditor not found")); return; }
	T->BeginCacheForCookedPlatformData(TP);
	const double T0 = FPlatformTime::Seconds();
	while (!T->IsCachedCookedPlatformDataLoaded(TP))
	{
		if (FPlatformTime::Seconds() - T0 > 600) { Problems.Add(TEXT("cook of the texture for WindowsNoEditor timed out (600 s)")); return; }
		FPlatformProcess::Sleep(0.01f);
	}
	TArray<TSharedPtr<FJsonValue>> Cooked;
	if (TMap<FString, FTexturePlatformData*>* CPD = T->GetCookedPlatformData())
	{
		for (auto& KV : *CPD)
		{
			FTexturePlatformData* PD = KV.Value;
			if (!PD) continue;
			TSharedRef<FJsonObject> C = MakeShared<FJsonObject>();
			C->SetStringField(TEXT("pixelFormat"), FString(TEXT("PF_")) + GPixelFormats[PD->PixelFormat].Name);
			// what the cooker WRITES: SerializePlatformData drops the top FirstMipToSerialize mips (texture LODBias + the target's texture group
			// settings), and the game's cooked data (what cue4export reads) starts at the first mip it kept
			const int32 NumMips = PD->Mips.Num();
			const int32 LastMip = FMath::Max(NumMips - 1, 0);
			const int32 TailMip = NumMips - (int32)PD->GetNumMipsInTail();
			int32 First = TP->GetTextureLODSettings().CalculateLODBias(PD->SizeX, PD->SizeY, T->MaxTextureSize, T->LODGroup, T->LODBias, 0, T->MipGenSettings, false);
			First = FMath::Clamp(First, 0, PD->GetNumMipsInTail() > 0 ? TailMip : LastMip);
			C->SetNumberField(TEXT("sizeX"), FMath::Max(1, PD->SizeX >> First));
			C->SetNumberField(TEXT("sizeY"), FMath::Max(1, PD->SizeY >> First));
			C->SetNumberField(TEXT("mips"), NumMips - First);
			C->SetNumberField(TEXT("firstMipToSerialize"), First);
			C->SetNumberField(TEXT("builtSizeX"), PD->SizeX);
			C->SetNumberField(TEXT("builtSizeY"), PD->SizeY);
			C->SetNumberField(TEXT("slices"), PD->GetNumSlices());
			Cooked.Add(MakeShared<FJsonValueObject>(C));
		}
	}
	if (Cooked.Num() == 0) Problems.Add(TEXT("no cooked platform data for WindowsNoEditor"));
	F->SetArrayField(TEXT("cookedWindows"), Cooked);
	T->ClearAllCachedCookedPlatformData();
}

static void MeshFacts(UStaticMesh* M, TSharedPtr<FJsonObject> F, TArray<FString>& Problems)
{
	FStaticMeshRenderData* RD = M->GetRenderData();
	if (!RD) { Problems.Add(TEXT("static mesh has no render data")); return; }
	// section flags / material indices and LOD screen sizes are resolved from the source models when the render resources are initialised or
	// the mesh is saved/cooked; neither happens in this -nullrhi commandlet after a load, so resolve them here exactly as the cooker does
	RD->ResolveSectionInfo(M);
	TArray<TSharedPtr<FJsonValue>> Lods;
	for (int32 i = 0; i < RD->LODResources.Num(); ++i)
	{
		FStaticMeshLODResources& L = RD->LODResources[i];
		FPositionVertexBuffer& PB = L.VertexBuffers.PositionVertexBuffer;
		FStaticMeshVertexBuffer& VB = L.VertexBuffers.StaticMeshVertexBuffer;
		TSharedRef<FJsonObject> J = MakeShared<FJsonObject>();
		J->SetNumberField(TEXT("verts"), PB.GetNumVertices());
		J->SetNumberField(TEXT("tris"), L.IndexBuffer.GetNumIndices() / 3);
		J->SetNumberField(TEXT("uvChannels"), VB.GetNumTexCoords());
		J->SetNumberField(TEXT("colorVerts"), L.VertexBuffers.ColorVertexBuffer.GetNumVertices());
		J->SetNumberField(TEXT("screenSize"), RD->ScreenSize[i].Default);
		J->SetNumberField(TEXT("sourceScreenSize"), M->IsSourceModelValid(i) ? M->GetSourceModel(i).ScreenSize.Default : -1.f);
		J->SetBoolField(TEXT("autoComputeScreenSize"), (bool)M->bAutoComputeLODScreenSize);
		J->SetBoolField(TEXT("fullPrecisionUVs"), VB.GetUseFullPrecisionUVs());
		J->SetBoolField(TEXT("highPrecisionTangents"), VB.GetUseHighPrecisionTangentBasis());
		TArray<TSharedPtr<FJsonValue>> Secs;
		for (const FStaticMeshSection& S : L.Sections)
		{
			TSharedRef<FJsonObject> SJ = MakeShared<FJsonObject>();
			SJ->SetNumberField(TEXT("materialIndex"), S.MaterialIndex);
			SJ->SetNumberField(TEXT("triangles"), S.NumTriangles);
			SJ->SetBoolField(TEXT("enableCollision"), S.bEnableCollision);
			SJ->SetBoolField(TEXT("castShadow"), S.bCastShadow);
			Secs.Add(MakeShared<FJsonValueObject>(SJ));
		}
		J->SetArrayField(TEXT("sections"), Secs);
		const uint32 N = PB.GetNumVertices();
		if (N && PB.GetVertexData() && VB.GetTexCoordData())
		{
			TSet<uint32> Used;
			for (int32 q = 0; q < L.IndexBuffer.GetNumIndices(); ++q) Used.Add(L.IndexBuffer.GetIndex(q));
			J->SetNumberField(TEXT("referencedVerts"), Used.Num());
			double X = 0, Y = 0, Z = 0;
			for (uint32 v : Used) { const FVector& P = PB.VertexPosition(v); X += P.X; Y += P.Y; Z += P.Z; }
			const double NU = FMath::Max(1, Used.Num());
			J->SetField(TEXT("centroid"), NumArr({ X / NU, Y / NU, Z / NU }));
			TArray<TSharedPtr<FJsonValue>> UVB;
			for (uint32 c = 0; c < VB.GetNumTexCoords(); ++c)
			{
				double U0 = 1e30, V0 = 1e30, U1 = -1e30, V1 = -1e30;
				for (uint32 v = 0; v < N; ++v) { const FVector2D UV = VB.GetVertexUV(v, c); U0 = FMath::Min<double>(U0, UV.X); V0 = FMath::Min<double>(V0, UV.Y); U1 = FMath::Max<double>(U1, UV.X); V1 = FMath::Max<double>(V1, UV.Y); }
				UVB.Add(NumArr({ U0, V0, U1, V1 }));
			}
			J->SetArrayField(TEXT("uvBounds"), UVB);
		}
		else Problems.Add(FString::Printf(TEXT("LOD%d: no CPU copy of the vertex data, centroid / UV bounds not available"), i));
		Lods.Add(MakeShared<FJsonValueObject>(J));
	}
	F->SetArrayField(TEXT("lods"), Lods);
	TSharedRef<FJsonObject> B = MakeShared<FJsonObject>();
	B->SetField(TEXT("origin"), NumArr({ RD->Bounds.Origin.X, RD->Bounds.Origin.Y, RD->Bounds.Origin.Z }));
	B->SetField(TEXT("extent"), NumArr({ RD->Bounds.BoxExtent.X, RD->Bounds.BoxExtent.Y, RD->Bounds.BoxExtent.Z }));
	B->SetNumberField(TEXT("radius"), RD->Bounds.SphereRadius);
	F->SetObjectField(TEXT("bounds"), B);
	TArray<TSharedPtr<FJsonValue>> Slots;
	for (const FStaticMaterial& SM : M->GetStaticMaterials())
	{
		TSharedRef<FJsonObject> S = MakeShared<FJsonObject>();
		S->SetStringField(TEXT("MaterialSlotName"), SM.MaterialSlotName.ToString());
		if (SM.MaterialInterface) S->SetStringField(TEXT("MaterialInterface"), SM.MaterialInterface->GetPathName()); else S->SetField(TEXT("MaterialInterface"), MakeShared<FJsonValueNull>());
		Slots.Add(MakeShared<FJsonValueObject>(S));
	}
	F->SetArrayField(TEXT("staticMaterials"), Slots);
	TArray<TSharedPtr<FJsonValue>> Socks;
	for (UStaticMeshSocket* S : M->Sockets) if (S) Socks.Add(MakeShared<FJsonValueObject>(ObjectJson(S)));
	F->SetArrayField(TEXT("sockets"), Socks);
	if (UBodySetup* BS = M->GetBodySetup()) F->SetObjectField(TEXT("bodySetup"), ObjectJson(BS));
	else F->SetField(TEXT("bodySetup"), MakeShared<FJsonValueNull>());
	if (UNavCollisionBase* NC = M->GetNavCollision()) F->SetObjectField(TEXT("navCollision"), ObjectJson(NC));
	else F->SetField(TEXT("navCollision"), MakeShared<FJsonValueNull>());
	TArray<TSharedPtr<FJsonValue>> Build;
	for (int32 i = 0; i < M->GetNumSourceModels(); ++i)
	{
		const FMeshBuildSettings& S = M->GetSourceModel(i).BuildSettings;
		TSharedRef<FJsonObject> J = MakeShared<FJsonObject>();
		J->SetBoolField(TEXT("recomputeNormals"), S.bRecomputeNormals);
		J->SetBoolField(TEXT("recomputeTangents"), S.bRecomputeTangents);
		J->SetBoolField(TEXT("removeDegenerates"), S.bRemoveDegenerates);
		J->SetBoolField(TEXT("generateLightmapUVs"), S.bGenerateLightmapUVs);
		Build.Add(MakeShared<FJsonValueObject>(J));
	}
	F->SetArrayField(TEXT("buildSettings"), Build);
}

static void MaterialParamNames(UMaterialInterface* MI, TSharedPtr<FJsonObject> F)
{
	TSet<FString> Names;
	TArray<FMaterialParameterInfo> Infos; TArray<FGuid> Ids;
	auto Add = [&]() { for (const FMaterialParameterInfo& I : Infos) Names.Add(I.Name.ToString()); Infos.Reset(); Ids.Reset(); };
	MI->GetAllScalarParameterInfo(Infos, Ids); Add();
	MI->GetAllVectorParameterInfo(Infos, Ids); Add();
	MI->GetAllTextureParameterInfo(Infos, Ids); Add();
	MI->GetAllRuntimeVirtualTextureParameterInfo(Infos, Ids); Add();
	MI->GetAllFontParameterInfo(Infos, Ids); Add();
	MI->GetAllStaticSwitchParameterInfo(Infos, Ids); Add();
	MI->GetAllStaticComponentMaskParameterInfo(Infos, Ids); Add();
	TArray<FString> Sorted = Names.Array();
	Sorted.Sort();
	TArray<TSharedPtr<FJsonValue>> A;
	for (const FString& S : Sorted) A.Add(MakeShared<FJsonValueString>(S));
	F->SetArrayField(TEXT("parameterNames"), A);

	// parameters that can affect the result: reachable from a material output of the base material through expression inputs
	// (material function calls pass all their inputs through). A parameter that exists but is not connected has no effect.
	TSet<FString> Used;
	TArray<FString> Outputs;
	if (UMaterial* Base = MI->GetMaterial())
	{
		TSet<UMaterialExpression*> Seen;
		TArray<UMaterialExpression*> Stack;
		for (int32 P = 0; P < MP_MAX; ++P)
		{
			FExpressionInput* In = Base->GetExpressionInputForProperty((EMaterialProperty)P);
			if (In && In->Expression)
			{
				Stack.Add(In->Expression);
				Outputs.Add(StaticEnum<EMaterialProperty>()->GetNameStringByValue(P));
			}
		}
		while (Stack.Num())
		{
			UMaterialExpression* E = Stack.Pop();
			if (!E || Seen.Contains(E)) continue;
			Seen.Add(E);
			const FName PN = E->GetParameterName();
			if (PN != NAME_None) Used.Add(PN.ToString());
			for (FExpressionInput* In : E->GetInputs()) if (In && In->Expression) Stack.Add(In->Expression);
		}
	}
	TArray<FString> U = Used.Array();
	U.Sort();
	TArray<TSharedPtr<FJsonValue>> UA, OA;
	for (const FString& S : U) UA.Add(MakeShared<FJsonValueString>(S));
	for (const FString& S : Outputs) OA.Add(MakeShared<FJsonValueString>(S));
	F->SetArrayField(TEXT("usedParameterNames"), UA);
	F->SetArrayField(TEXT("connectedOutputs"), OA);
}

static FString Write(const TSharedPtr<FJsonObject>& O)
{
	FString Out;
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> W = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&Out);
	FJsonSerializer::Serialize(O.ToSharedRef(), W);
	return Out;
}
} // namespace ItrAudit

using namespace ItrAudit;

FString UItrShowcaseAudit::ApplyProps(UObject* Obj, const FString& PropsJson)
{
	TArray<FString> P;
	if (!Obj) return TEXT("ApplyProps: no object");
	TSharedPtr<FJsonObject> Props = ParseObj(PropsJson, P, TEXT("props"));
	Obj->Modify();
	ApplyAll(Obj, Props, {}, P);
	Obj->PostEditChange();
	Obj->MarkPackageDirty();
	return Join(P);
}

FString UItrShowcaseAudit::CreateTexture2D(const FString& AssetPath, const FString& PngFile, const FString& PropsJson)
{
	TArray<FString> P;
	TSharedPtr<FJsonObject> Props = ParseObj(PropsJson, P, TEXT("props"));
	TArray<uint8> File;
	if (!FFileHelper::LoadFileToArray(File, *PngFile)) { P.Add(FString::Printf(TEXT("cannot read %s"), *PngFile)); return Join(P); }
	int32 SizeX = 0, SizeY = 0, Slices = 1;
	ETextureSourceFormat Fmt = TSF_BGRA8;
	TArray64<uint8> Raw;
	if (PngFile.EndsWith(TEXT(".rgba16f")))
	{
		// float source: 'F16R' + uint32 sizeX, sizeY, slices + the half-float RGBA pixels of mip 0 (all slices) exactly as the game cooked them
		if (File.Num() < 16 || FMemory::Memcmp(File.GetData(), "F16R", 4) != 0) { P.Add(FString::Printf(TEXT("%s: not an F16R float texture file"), *PngFile)); return Join(P); }
		const uint32* H = reinterpret_cast<const uint32*>(File.GetData() + 4);
		SizeX = (int32)H[0]; SizeY = (int32)H[1]; Slices = (int32)H[2];
		const int64 Want = (int64)SizeX * SizeY * Slices * 8;
		if ((int64)File.Num() - 16 != Want) { P.Add(FString::Printf(TEXT("%s: %lld bytes of pixels, %dx%dx%d RGBA16F needs %lld"), *PngFile, (int64)File.Num() - 16, SizeX, SizeY, Slices, Want)); return Join(P); }
		Raw.Append(File.GetData() + 16, (int64)Want);
		Fmt = TSF_RGBA16F;
	}
	else
	{
		IImageWrapperModule& IWM = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
		TSharedPtr<IImageWrapper> W = IWM.CreateImageWrapper(EImageFormat::PNG);
		if (!W.IsValid() || !W->SetCompressed(File.GetData(), File.Num())) { P.Add(FString::Printf(TEXT("%s is not a readable PNG"), *PngFile)); return Join(P); }
		if (W->GetBitDepth() != 8) { P.Add(FString::Printf(TEXT("%s: bit depth %d, the audit PNG textures are 8-bit"), *PngFile, W->GetBitDepth())); return Join(P); }
		if (!W->GetRaw(ERGBFormat::BGRA, 8, Raw)) { P.Add(FString::Printf(TEXT("%s: PNG decode failed"), *PngFile)); return Join(P); }
		SizeX = W->GetWidth(); SizeY = W->GetHeight();
	}
	bool bCreated = false;
	UTexture* T = Cast<UTexture>(FindOrCreateAsset(AssetPath, Slices == 6 ? (UClass*)UTextureCube::StaticClass() : (UClass*)UTexture2D::StaticClass(), P, bCreated));
	if (!T) return Join(P);
	T->PreEditChange(nullptr);
	if (!bCreated) ResetToDefaults(T);
	T->Source.Init(SizeX, SizeY, Slices, 1, Fmt, Raw.GetData());
	ApplyAll(T, Props, {}, P);
	T->PostEditChange();
	T->MarkPackageDirty();
	return Join(P);
}

FString UItrShowcaseAudit::CreateGeneric(const FString& AssetPath, const FString& ClassPath, const FString& PropsJson)
{
	TArray<FString> P;
	TSharedPtr<FJsonObject> Props = ParseObj(PropsJson, P, TEXT("props"));
	UClass* Cls = FindClassByName(ClassPath);
	if (!Cls) { P.Add(FString::Printf(TEXT("class %s not found in this editor"), *ClassPath)); return Join(P); }
	bool bCreated = false;
	UObject* O = FindOrCreateAsset(AssetPath, Cls, P, bCreated);
	if (!O) return Join(P);
	O->Modify();
	if (!bCreated) ResetToDefaults(O);
	ApplyAll(O, Props, {}, P);
	O->PostEditChange();
	O->MarkPackageDirty();
	return Join(P);
}

FString UItrShowcaseAudit::CreatePackageGraph(const FString& AssetPath, const FString& ClassPath, const FString& PropsJson, const FString& SubobjectsJson)
{
	TArray<FString> P;
	TSharedPtr<FJsonObject> Props = ParseObj(PropsJson, P, TEXT("props"));
	TArray<TSharedPtr<FJsonValue>> Subs;
	if (!SubobjectsJson.IsEmpty() && !FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(SubobjectsJson), Subs)) { P.Add(TEXT("subobjects: invalid JSON")); return Join(P); }
	UClass* Cls = FindClassByName(ClassPath);
	if (!Cls) { P.Add(FString::Printf(TEXT("class %s not found in this editor"), *ClassPath)); return Join(P); }
	// GPU particle emitters: the editor rebuilds an emitter's module data every time its package loads (UParticleEmitter::Build), from
	// Distribution objects that cooked data has stripped (null pointers -> access violation, e.g. UParticleModuleColorOverLife::CompileModule),
	// and it would overwrite the game's computed ResourceData anyway. They need the fork's engine patch "ItrKeepCookedParticleBuild"
	// (package metadata marker set below; ParticleComponents.cpp / ParticleModules.cpp). Until the patched engine is built (the project file
	// Config/ItrEngineParticlePatch.txt says so) such a system is refused instead of crashing the shared editor.
	if (Cls->IsChildOf(UParticleSystem::StaticClass()))
	{
		bool bGpu = false;
		for (const TSharedPtr<FJsonValue>& V : Subs) bGpu |= V->AsObject()->GetStringField(TEXT("class")).EndsWith(TEXT("ParticleModuleTypeDataGpu"));
		if (bGpu && !FPaths::FileExists(FPaths::ProjectConfigDir() / TEXT("ItrEngineParticlePatch.txt")))
		{
			P.Add(TEXT("GPU particle emitters (ParticleModuleTypeDataGpu) need the engine patch ItrKeepCookedParticleBuild (the stock editor crashes while loading them); not created. After building the patched engine add Config/ItrEngineParticlePatch.txt to the project."));
			return Join(P);
		}
	}
	bool bCreated = false;
	UObject* Main = FindOrCreateAsset(AssetPath, Cls, P, bCreated);
	if (!Main) return Join(P);
	Main->Modify();
	if (Cast<UParticleSystem>(Main))
	{
		// Cooked particle data cannot be rebuilt by the editor (GPU emitters keep only baked lookup tables and the game's computed ResourceData;
		// the Distribution objects are stripped). This package-level marker makes the fork's UParticleEmitter::Build / TypeDataGpu::Build keep the
		// cooked state (engine patch "ItrKeepCookedParticleBuild", ParticleComponents.cpp + ParticleModules.cpp); stock builds ignore it.
		// RootMetaDataMap is UMetaData's place for package-level values (a value keyed on the UPackage object may not survive save/reload).
		// Set before any PostEditChange below, so no Build on this asset recompiles the modules.
		Main->GetOutermost()->GetMetaData()->RootMetaDataMap.Add(TEXT("ItrKeepCookedParticleBuild"), TEXT("true"));
	}
	// 1. every subobject, outers first, with its game name
	TArray<TPair<UObject*, TSharedPtr<FJsonObject>>> Made;
	TSet<UObject*> MadeByConstructor;   // subobjects a parent's constructor / PostInitProperties already created (a module's default distributions ...)
	for (const TSharedPtr<FJsonValue>& V : Subs)
	{
		const TSharedPtr<FJsonObject> S = V->AsObject();
		const FString Name = S->GetStringField(TEXT("name"));
		UClass* SC = FindClassByName(S->GetStringField(TEXT("class")));
		if (!SC) SC = FindClassByName(FPackageName::ObjectPathToObjectName(S->GetStringField(TEXT("class"))));
		UObject* Outer = StaticFindObject(UObject::StaticClass(), nullptr, *S->GetStringField(TEXT("outer")));
		if (!SC || !Outer) { P.Add(FString::Printf(TEXT("subobject %s: %s"), *Name, !SC ? *(TEXT("class not found: ") + S->GetStringField(TEXT("class"))) : *(TEXT("outer not found: ") + S->GetStringField(TEXT("outer"))))); continue; }
		UObject* O = StaticFindObject(SC, Outer, *Name);
		if (!O) O = NewObject<UObject>(Outer, SC, FName(*Name), RF_Transactional | RF_Public);
		else MadeByConstructor.Add(O);
		Made.Add(TPair<UObject*, TSharedPtr<FJsonObject>>(O, S));
	}
	// 2. properties (now every reference inside the package resolves)
	ApplyAll(Main, Props, {}, P);
	for (auto& M : Made)
	{
		const TSharedPtr<FJsonObject>* SP = nullptr;
		// the game's cooked values are only those that differ from the class default: an object the constructor already filled (e.g. a
		// default distribution with Constant = 1) goes back to the class default first
		if (MadeByConstructor.Contains(M.Key)) ResetToDefaults(M.Key);
		if (M.Value->TryGetObjectField(TEXT("props"), SP)) ApplyAll(M.Key, *SP, {}, P);
	}
	// 3. class finishing
	// Cooked particle data has no editor-only inputs: modules of GPU emitters keep only their baked lookup tables (Distribution = null) and the
	// type data keeps its cooked EmitterInfo. UE itself skips the editor-side module compile / type data build for packages cooked for the
	// editor (UParticleEmitter::Build, UParticleModuleTypeDataGpu::Build): so does this asset while its object graph is finished, and the
	// game's values are applied again after. The flag is reset before the package is saved.
	struct FCookedForEditorScope
	{
		UPackage* Pkg; uint8 Old;
		FCookedForEditorScope(UObject* O, bool bOn) : Pkg(bOn ? O->GetOutermost() : nullptr), Old(Pkg ? Pkg->bIsCookedForEditor : 0) { if (Pkg) Pkg->bIsCookedForEditor = true; }
		~FCookedForEditorScope() { if (Pkg) Pkg->bIsCookedForEditor = Old; }
	} CookedScope(Main, Cast<UParticleSystem>(Main) != nullptr);
	if (UParticleSystem* PS = Cast<UParticleSystem>(Main))
	{
		for (UParticleEmitter* E : PS->Emitters) if (E) E->UpdateModuleLists();
		PS->UpdateAllModuleLists();
	}
	USoundCue* Cue = Props.IsValid() && Props->Values.Num() ? Cast<USoundCue>(Main) : nullptr;   // the editor graph once the nodes are linked
	if (Cue)
	{
		Cue->AllNodes.Reset();
		for (auto& M : Made) if (USoundNode* N = Cast<USoundNode>(M.Key)) { Cue->AllNodes.Add(N); if (!N->GraphNode) Cue->SetupSoundNode(N, false); }
		Cue->LinkGraphNodesFromSoundNodes();
		Cue->CacheAggregateValues();
	}
	for (auto& M : Made) M.Key->PostEditChange();
	Main->PostEditChange();
	// the game's values once more after the editor's recompute (e.g. particle peak counts, distribution dirty flags): the cooked state
	TArray<FString> Again;
	ApplyAll(Main, Props, {}, Again);
	for (auto& M : Made)
	{
		const TSharedPtr<FJsonObject>* SP = nullptr;
		if (M.Value->TryGetObjectField(TEXT("props"), SP)) ApplyAll(M.Key, *SP, {}, Again);
	}
	Main->MarkPackageDirty();
	return Join(P);
}

FString UItrShowcaseAudit::CreateUserDefinedStruct(const FString& AssetPath, const FString& FieldsJson, const FString& DefaultsJson)
{
	TArray<FString> P;
	TArray<TSharedPtr<FJsonValue>> Fields;
	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(FieldsJson), Fields)) { P.Add(TEXT("fields: invalid JSON")); return Join(P); }
	TSharedPtr<FJsonObject> Defaults = ParseObj(DefaultsJson, P, TEXT("defaults"));
	const FString Name = FPackageName::GetLongPackageAssetName(AssetPath);
	if (LoadObject<UObject>(nullptr, *(AssetPath + TEXT(".") + Name), nullptr, LOAD_NoWarn | LOAD_Quiet)) { P.Add(TEXT("an asset exists at the path (the replace step should have removed it)")); return Join(P); }
	UPackage* Pkg = CreatePackage(*AssetPath);
	UUserDefinedStruct* S = FStructureEditorUtils::CreateUserDefinedStruct(Pkg, FName(*Name), RF_Public | RF_Standalone | RF_Transactional);
	if (!S) { P.Add(TEXT("CreateUserDefinedStruct failed")); return Join(P); }
	TArray<FGuid> Initial;
	for (const FStructVariableDescription& D : FStructureEditorUtils::GetVarDesc(S)) Initial.Add(D.VarGuid);
	for (const TSharedPtr<FJsonValue>& V : Fields)
	{
		const TSharedPtr<FJsonObject> F = V->AsObject();
		const FString VarName = F->GetStringField(TEXT("name"));
		FString Type; F->TryGetStringField(TEXT("specType"), Type);
		FEdGraphPinType PT; FString Err;
		if (Type.IsEmpty() || !ItrBPGenParsePinType(Type, PT, Err)) { P.Add(FString::Printf(TEXT("member %s: type %s not expressible (%s)"), *VarName, *Type, *Err)); continue; }
		if (!FStructureEditorUtils::AddVariable(S, PT)) { P.Add(FString::Printf(TEXT("member %s: AddVariable failed"), *VarName)); continue; }
		FStructVariableDescription& D = FStructureEditorUtils::GetVarDesc(S).Last();
		// "Friendly_N_GUID": the game's exact member name and GUID (Blueprints and saved data address members by them)
		int32 Last = INDEX_NONE; VarName.FindLastChar(TEXT('_'), Last);
		FGuid G;
		if (Last != INDEX_NONE && FGuid::Parse(VarName.Mid(Last + 1), G)) D.VarGuid = G;
		else P.Add(FString::Printf(TEXT("member %s: no GUID suffix in the name"), *VarName));
		D.VarName = FName(*VarName);
		int32 First = INDEX_NONE; VarName.FindChar(TEXT('_'), First);
		D.FriendlyName = First != INDEX_NONE ? VarName.Left(First) : VarName;
	}
	for (const FGuid& G : Initial) FStructureEditorUtils::RemoveVariable(S, G);
	FStructureEditorUtils::CompileStructure(S);
	// default values (as the generator converts them to text)
	if (Defaults.IsValid())
	{
		for (const auto& KV : Defaults->Values)
		{
			FProperty* Prop = S->FindPropertyByName(FName(*KV.Key));
			FStructVariableDescription* D = nullptr;
			for (FStructVariableDescription& X : FStructureEditorUtils::GetVarDesc(S)) if (X.VarName == FName(*KV.Key)) D = &X;
			if (!Prop || !D) { P.Add(FString::Printf(TEXT("default %s: no such member"), *KV.Key)); continue; }
			if (KV.Value->Type == EJson::Null || (KV.Value->Type == EJson::Array && KV.Value->AsArray().Num() == 0)) continue;   // the type's default
			P.Add(FString::Printf(TEXT("default %s: non-empty struct member defaults are not reproduced yet"), *KV.Key));
		}
	}
	FStructureEditorUtils::OnStructureChanged(S);
	FAssetRegistryModule::AssetCreated(S);
	S->MarkPackageDirty();
	return Join(P);
}

FString UItrShowcaseAudit::SetupMaterialInstance(const FString& AssetPath, const FString& PropsJson)
{
	TArray<FString> P;
	bool bCreated = false;
	UMaterialInstanceConstant* MI = Cast<UMaterialInstanceConstant>(FindOrCreateAsset(AssetPath, UMaterialInstanceConstant::StaticClass(), P, bCreated));
	if (!MI) return Join(P);
	TSharedPtr<FJsonObject> Props = ParseObj(PropsJson, P, TEXT("props"));
	if (!Props.IsValid()) return Join(P);
	UMaterialInterface* Parent = nullptr;
	FString ParentPath;
	if (Props->TryGetStringField(TEXT("Parent"), ParentPath))
	{
		Parent = LoadObject<UMaterialInterface>(nullptr, *ParentPath, nullptr, LOAD_NoWarn | LOAD_Quiet);
		if (!Parent) P.Add(FString::Printf(TEXT("Parent %s not found in this project"), *ParentPath));
	}
	MI->PreEditChange(nullptr);
	ResetToDefaults(MI);
	MI->ClearParameterValuesEditorOnly();
	MI->SetParentEditorOnly(Parent, false);
	// derived data the editor computes from the parent chain on save: not set from the game (compared, see the global whitelist)
	ApplyAll(MI, Props, { TEXT("Parent"), TEXT("CachedReferencedTextures"), TEXT("TextureStreamingData"), TEXT("CachedLayerParameters") }, P);
	// the layer stack just set decides which layer / blend parameters exist (CachedLayerParameters): without this refresh
	// GetStaticParameterValues does not list the layers' static switches and the permutation drops them (T-116)
	MI->UpdateCachedLayerParameters();
	FStaticParameterSet SP;
	MI->GetStaticParameterValues(SP);   // as the properties set them
	// material layer stacks (T-116), in the merged copy (StaticParameters is private): the cooked stack has Layers / Blends / LayerStates only; the editor-only arrays (names, guids, link
	// states, relative restrictions) must have the same sizes. NotFromParent: the stack is this instance's own, never re-linked to the parent's.
	for (FStaticMaterialLayersParameter& LP : SP.MaterialLayersParameters)
	{
		// GetStaticParameterValues includes inherited stacks. Only cooked local
		// overrides replace the parent stack; leave pure inheritance untouched.
		const bool bLocalOverride = MI->GetStaticParameters().MaterialLayersParameters.ContainsByPredicate(
			[&LP](const FStaticMaterialLayersParameter& Local) { return Local.bOverride && Local.ParameterInfo == LP.ParameterInfo; });
		if (!bLocalOverride) continue;
		FMaterialLayersFunctions& L = LP.Value;
		const int32 N = L.Layers.Num();
		if (L.LayerStates.Num() != N) { P.Add(FString::Printf(TEXT("layer stack %s: %d layers, %d layer states"), *LP.ParameterInfo.Name.ToString(), N, L.LayerStates.Num())); L.LayerStates.SetNum(N); }
		if (L.Blends.Num() != FMath::Max(0, N - 1)) P.Add(FString::Printf(TEXT("layer stack %s: %d layers, %d blends"), *LP.ParameterInfo.Name.ToString(), N, L.Blends.Num()));
#if WITH_EDITORONLY_DATA
		L.LayerNames.SetNum(N);
		L.RestrictToLayerRelatives.SetNum(N);
		L.RestrictToBlendRelatives.SetNum(L.Blends.Num());
		L.LayerGuids.SetNum(N);
		L.LayerLinkStates.SetNum(N);
		for (int32 i = 0; i < N; ++i)
		{
			L.LayerNames[i] = i == 0 ? FText::FromString(TEXT("Background")) : FText::FromString(FString::Printf(TEXT("Layer %d"), i));
			L.LayerGuids[i] = i == 0 ? FMaterialLayersFunctions::BackgroundGuid : FGuid(0x7116, (uint32)i, 0, 0);
			L.LayerLinkStates[i] = EMaterialLayerLinkState::NotFromParent;
		}
		L.DeletedParentLayerGuids.Empty();
		// NotFromParent alone does not prevent ResolveParent from inserting every
		// unlinked parent layer. Cooked Value is the complete replacement stack.
		FMaterialLayersFunctions ParentLayers;
		FGuid ParentExpressionGuid;
		if (Parent && Parent->GetMaterialLayersParameterValue(LP.ParameterInfo, ParentLayers, ParentExpressionGuid))
		{
			for (int32 i = 1; i < ParentLayers.LayerGuids.Num(); ++i)
				L.DeletedParentLayerGuids.AddUnique(ParentLayers.LayerGuids[i]);
		}

#endif
	}
	FMaterialInstanceBasePropertyOverrides BO = MI->BasePropertyOverrides;
	MI->UpdateStaticPermutation(SP, BO, true);
	MI->PostEditChange();
	MI->MarkPackageDirty();
	return Join(P);
}

FString UItrShowcaseAudit::FinishStaticMesh(UStaticMesh* Mesh, const FString& NodeJson)
{
	TArray<FString> P;
	if (!Mesh) return TEXT("FinishStaticMesh: no mesh");
	TSharedPtr<FJsonObject> Node = ParseObj(NodeJson, P, TEXT("node"));
	if (!Node.IsValid()) return Join(P);
	Mesh->Modify();
	// The FBX importer sets LightMapCoordinateIndex itself (1 when the file has a second UV channel). The cooked mesh lists the property only
	// when it differs from the class default (0), so reset it here; the props pass below writes the game's value when it is listed.
	Mesh->SetLightMapCoordinateIndex(0);
	// Same for LightMapResolution: the FBX import leaves its own value (64, e.g. SM_Debris_Cigarette_Butts_02_b) where the cooked mesh has the
	// class default (the property is listed only when it differs); the props pass writes the game's value when it is listed.
	Mesh->SetLightMapResolution(GetDefault<UStaticMesh>()->GetLightMapResolution());

	// build settings + LOD screen sizes: rebuild the cooked vertex data as it is (no recomputed normals/tangents, no generated lightmap UVs)
	const TArray<TSharedPtr<FJsonValue>>* Lods = nullptr;
	Node->TryGetArrayField(TEXT("lods"), Lods);
	const int32 NL = Lods ? Lods->Num() : 0;
	if (Mesh->GetNumSourceModels() != NL) P.Add(FString::Printf(TEXT("the import made %d LODs, the game mesh has %d"), Mesh->GetNumSourceModels(), NL));
	Mesh->bAutoComputeLODScreenSize = false;
	for (int32 i = 0; i < FMath::Min(NL, Mesh->GetNumSourceModels()); ++i)
	{
		const TSharedPtr<FJsonObject> L = (*Lods)[i]->AsObject();
		FStaticMeshSourceModel& SM = Mesh->GetSourceModel(i);
		SM.BuildSettings.bRecomputeNormals = false;
		SM.BuildSettings.bRecomputeTangents = false;
		SM.BuildSettings.bRemoveDegenerates = false;
		SM.BuildSettings.bGenerateLightmapUVs = false;
		SM.BuildSettings.bUseFullPrecisionUVs = L->GetBoolField(TEXT("fullPrecisionUVs"));
		SM.BuildSettings.bUseHighPrecisionTangentBasis = L->GetBoolField(TEXT("highPrecisionTangents"));
		SM.ScreenSize.Default = (float)L->GetNumberField(TEXT("screenSize"));
		// per-section flags as cooked (collision / shadow); the material index stays as the import mapped it (compared afterwards)
		const TArray<TSharedPtr<FJsonValue>>* Secs = nullptr;
		if (L->TryGetArrayField(TEXT("sections"), Secs))
		{
			for (int32 s = 0; s < Secs->Num(); ++s)
			{
				const TSharedPtr<FJsonObject> SJ = (*Secs)[s]->AsObject();
				FMeshSectionInfo Info = Mesh->GetSectionInfoMap().Get(i, s);
				Info.bEnableCollision = SJ->GetBoolField(TEXT("enableCollision"));
				Info.bCastShadow = SJ->GetBoolField(TEXT("castShadow"));
				Mesh->GetSectionInfoMap().Set(i, s, Info);
			}
		}
	}

	// material slots: names and materials in the game's order (the FBX carried the slot names in that order; sections map by index)
	const TArray<TSharedPtr<FJsonValue>>* Slots = nullptr;
	Node->TryGetArrayField(TEXT("staticMaterials"), Slots);
	TArray<FStaticMaterial>& SMs = Mesh->GetStaticMaterials();
	if (Slots)
	{
		if (SMs.Num() != Slots->Num())
		{
			// T-116: the FBX import drops slots no polygon uses (SM_Buildings_Construction_Wall_Bricks_Broken_02_b: game slots Outer (unused) + Bricks), so
			// the imported sections carry the imported slot numbers (Bricks = 0). Map each imported slot to the game slot of the same name and re-number
			// the sections to the game's slot numbers (the sections then use slot 1 and the per-slot UV densities land on the right slot).
			auto Alnum0 = [](const FString& In) { FString R; for (TCHAR C : In) if (FChar::IsAlnum(C)) R.AppendChar(FChar::ToLower(C)); return R; };
			TArray<int32> ImpToGame;
			TSet<int32> Taken;
			for (int32 k = 0; k < SMs.Num(); ++k)
			{
				const FString Imp = Alnum0(SMs[k].ImportedMaterialSlotName.ToString());
				int32 Found = INDEX_NONE;
				for (int32 pass = 0; pass < 2 && Found == INDEX_NONE; ++pass)
					for (int32 g = 0; g < Slots->Num() && Found == INDEX_NONE; ++g)
					{
						if (Taken.Contains(g)) continue;
						const FString GN = Alnum0((*Slots)[g]->AsObject()->GetStringField(TEXT("MaterialSlotName")));
						if (pass == 0 ? Imp == GN : (!Imp.IsEmpty() && Imp.StartsWith(GN) && !GN.IsEmpty())) Found = g;
					}
				if (Found == INDEX_NONE) { Found = FMath::Min(k, Slots->Num() - 1); P.Add(FString::Printf(TEXT("imported slot %d (%s) has no game slot of that name; kept at index %d"), k, *SMs[k].ImportedMaterialSlotName.ToString(), Found)); }
				Taken.Add(Found);
				ImpToGame.Add(Found);
			}
			{
				TArray<FStaticMaterial> Placed;                       // the imported slots at their game slot numbers; the slots no polygon uses stay empty
				Placed.SetNum(Slots->Num());
				for (int32 k = 0; k < SMs.Num(); ++k) Placed[ImpToGame[k]] = SMs[k];
				SMs = Placed;
			}
			for (int32 i = 0; i < Mesh->GetNumSourceModels(); ++i)
			{
				const int32 NumSecs = Mesh->GetSectionInfoMap().GetSectionNumber(i);
				for (int32 s = 0; s < NumSecs; ++s)
				{
					FMeshSectionInfo Info = Mesh->GetSectionInfoMap().Get(i, s);
					if (ImpToGame.IsValidIndex(Info.MaterialIndex))
					{
						Info.MaterialIndex = ImpToGame[Info.MaterialIndex];
						Mesh->GetSectionInfoMap().Set(i, s, Info);
					}
				}
			}
		}
		for (int32 i = 0; i < Slots->Num(); ++i)
		{
			const TSharedPtr<FJsonObject> S = (*Slots)[i]->AsObject();
			const FName SlotName(*S->GetStringField(TEXT("MaterialSlotName")));
			// the FBX importer makes material names unique and replaces '.' ("net2.001" -> "net2_001", a repeated "x" -> "x_ncl1_1"): compare letters and digits only,
			// the imported name may carry a suffix
			auto Alnum = [](const FString& In) { FString R; for (TCHAR C : In) if (FChar::IsAlnum(C)) R.AppendChar(FChar::ToLower(C)); return R; };
			if (SMs[i].ImportedMaterialSlotName != NAME_None && SMs[i].ImportedMaterialSlotName != SlotName
				&& !Alnum(SMs[i].ImportedMaterialSlotName.ToString()).StartsWith(Alnum(SlotName.ToString())))
				P.Add(FString::Printf(TEXT("slot %d: the import named it %s, the game %s"), i, *SMs[i].ImportedMaterialSlotName.ToString(), *SlotName.ToString()));
			SMs[i].MaterialSlotName = SlotName;
			SMs[i].ImportedMaterialSlotName = SlotName;
			FString MPath;
			UMaterialInterface* Mat = nullptr;
			if (S->TryGetStringField(TEXT("MaterialInterface"), MPath) && !MPath.IsEmpty())
			{
				Mat = LoadObject<UMaterialInterface>(nullptr, *MPath, nullptr, LOAD_NoWarn | LOAD_Quiet);
				if (!Mat) P.Add(FString::Printf(TEXT("slot %d: material %s not found in this project"), i, *MPath));
			}
			SMs[i].MaterialInterface = Mat;
		}
	}
	Mesh->Build(true);

	// sockets, exactly as cooked
	Mesh->Sockets.Empty();
	const TArray<TSharedPtr<FJsonValue>>* Socks = nullptr;
	if (Node->TryGetArrayField(TEXT("sockets"), Socks))
	{
		for (const TSharedPtr<FJsonValue>& V : *Socks)
		{
			UStaticMeshSocket* S = NewObject<UStaticMeshSocket>(Mesh, NAME_None, RF_Transactional);
			ApplyAll(S, V->AsObject(), {}, P);
			Mesh->Sockets.Add(S);
		}
	}

	// body setup: the cooked simple collision shapes and flags, set directly (no FBX UCX re-fit)
	const TSharedPtr<FJsonObject>* BSJ = nullptr;
	FVector GameBuildScale(1.0f, 1.0f, 1.0f);
	Mesh->CreateBodySetup();
	if (UBodySetup* BS = Mesh->GetBodySetup())
	{
		BS->Modify();
		BS->RemoveSimpleCollision();
		if (Node->TryGetObjectField(TEXT("bodySetup"), BSJ)) ApplyAll(BS, *BSJ, {}, P);
		GameBuildScale = BS->BuildScale3D;
		BS->InvalidatePhysicsData();
		BS->CreatePhysicsMeshes();
		Mesh->bCustomizedCollision = true;
	}

	// remaining properties; derived ones (bounds extension, UV density) are computed by the build and compared, not set
	const TSharedPtr<FJsonObject>* Props = nullptr;
	if (Node->TryGetObjectField(TEXT("props"), Props))
		ApplyAll(Mesh, *Props, { TEXT("ExtendedBounds"), TEXT("LightmapUVDensity"), TEXT("LightingGuid") }, P);
	Mesh->PostEditChange();
	// T-116: a mesh the game built at a source scale (army_bed_*: BuildScale3D 100, convex shapes in cm) stores that scale in its body setup. The
	// build above rescales the simple collision by (build settings scale / body setup scale) = 1/100 and resets BuildScale3D to 1, so the
	// cooked shapes are written again exactly as the game has them.
	// ImportedMaterialSlotName as cooked (the FBX material names the import used differ from it for some meshes, e.g. army_bed_*). Set after the
	// last build so that no build matches polygon groups against a changed name.
	{
		const TArray<TSharedPtr<FJsonValue>>* SlotProps = nullptr;
		if (Node->TryGetArrayField(TEXT("staticMaterialsProps"), SlotProps))
		{
			TArray<FStaticMaterial>& Mats = Mesh->GetStaticMaterials();
			for (int32 i = 0; i < FMath::Min(Mats.Num(), SlotProps->Num()); ++i)
			{
				const TSharedPtr<FJsonObject> SO = (*SlotProps)[i]->AsObject();
				FString Imp;
				if (SO.IsValid() && SO->TryGetStringField(TEXT("ImportedMaterialSlotName"), Imp)) Mats[i].ImportedMaterialSlotName = FName(*Imp);
			}
		}
	}
	if (BSJ)
	{
		if (UBodySetup* BS = Mesh->GetBodySetup())
		{
			if (!BS->BuildScale3D.Equals(GameBuildScale, 0.0f))
			{
				TArray<FString> P2;
				BS->Modify();
				BS->RemoveSimpleCollision();
				ApplyAll(BS, *BSJ, {}, P2);
				BS->InvalidatePhysicsData();
				BS->CreatePhysicsMeshes();
			}
		}
	}
	// T-116: the render data the build returns can come from the derived data cache with the section material indices of an earlier state (the
	// FBX import's polygon-group order). Resolve them from the section info map (the game's order, e.g. SM_WaterPlane: section 0 = slot 1) and
	// recompute the per-slot UV densities from the resolved sections.
	if (FStaticMeshRenderData* RD = Mesh->GetRenderData())
	{
		RD->ResolveSectionInfo(Mesh);
		Mesh->UpdateUVChannelData(true);
		// T-116: UpdateUVChannelData recomputes only the slots a section uses; a slot no triangle uses (Bricks_Broken_02_b slot 0 "Outer") kept the density
		// of the slot numbering the import started with. The game has 0 there (no triangles, no density).
		if (RD->LODResources.Num() > 0)
		{
			TSet<int32> UsedSlots;
			// the section info map is authoritative for which slot a section uses (the render sections of this build may still carry the import's numbering)
			for (int32 s = 0; s < Mesh->GetSectionInfoMap().GetSectionNumber(0); ++s) UsedSlots.Add(Mesh->GetSectionInfoMap().Get(0, s).MaterialIndex);
			TArray<FStaticMaterial>& Mats = Mesh->GetStaticMaterials();
			for (int32 i = 0; i < Mats.Num(); ++i)
				if (!UsedSlots.Contains(i)) Mats[i].UVChannelData = FMeshUVChannelInfo(0.0f);
		}
	}
	Mesh->MarkPackageDirty();
	return Join(P);
}

FString UItrShowcaseAudit::DumpAsset(const FString& ObjectPath)
{
	TArray<FString> P;
	UObject* Obj = LoadObject<UObject>(nullptr, *ObjectPath, nullptr, LOAD_NoWarn | LOAD_Quiet);
	TSharedPtr<FJsonObject> Root = MakeShared<FJsonObject>();
	Root->SetStringField(TEXT("path"), ObjectPath);
	if (!Obj)
	{
		Root->SetStringField(TEXT("error"), TEXT("cannot load"));
		return Write(Root);
	}
	Root->SetStringField(TEXT("class"), Obj->GetClass()->GetPathName());
	Root->SetObjectField(TEXT("props"), ObjectJson(Obj));
	TSharedPtr<FJsonObject> F = MakeShared<FJsonObject>();
	if (UTexture* T = Cast<UTexture>(Obj)) TextureFacts(T, F, P);
	if (UStaticMesh* M = Cast<UStaticMesh>(Obj)) MeshFacts(M, F, P);
	if (UMaterialInterface* MI = Cast<UMaterialInterface>(Obj)) MaterialParamNames(MI, F);
	if (UUserDefinedStruct* US = Cast<UUserDefinedStruct>(Obj))
	{
		TArray<TSharedPtr<FJsonValue>> Mem;
		for (TFieldIterator<FProperty> It(US); It; ++It)
		{
			TSharedRef<FJsonObject> M = MakeShared<FJsonObject>();
			M->SetStringField(TEXT("name"), It->GetName());
			M->SetStringField(TEXT("type"), It->GetClass()->GetName());
			Mem.Add(MakeShared<FJsonValueObject>(M));
		}
		F->SetArrayField(TEXT("members"), Mem);
	}
	Root->SetObjectField(TEXT("facts"), F);
	TArray<TSharedPtr<FJsonValue>> PA;
	for (const FString& S : P) PA.Add(MakeShared<FJsonValueString>(S));
	Root->SetArrayField(TEXT("problems"), PA);
	return Write(Root);
}

FString UItrShowcaseAudit::ConnectMaterialPropertyIndex(UMaterial* Material, UMaterialExpression* Expression, const FString& OutputName, int32 PropertyIndex)
{
	if (!Material || !Expression) return TEXT("ConnectMaterialPropertyIndex: no material or expression");
	if (PropertyIndex < 0 || PropertyIndex >= MP_MAX) return FString::Printf(TEXT("ConnectMaterialPropertyIndex: bad property %d"), PropertyIndex);
	FExpressionInput* In = Material->GetExpressionInputForProperty((EMaterialProperty)PropertyIndex);
	if (!In) return FString::Printf(TEXT("ConnectMaterialPropertyIndex: material has no input %d"), PropertyIndex);
	int32 OutIndex = INDEX_NONE;
	const TArray<FExpressionOutput>& Outs = Expression->GetOutputs();
	for (int32 i = 0; i < Outs.Num(); ++i)
		if ((OutputName.IsEmpty() && i == 0) || Outs[i].OutputName.ToString() == OutputName) { OutIndex = i; break; }
	if (OutIndex == INDEX_NONE) return FString::Printf(TEXT("ConnectMaterialPropertyIndex: %s has no output '%s'"), *Expression->GetName(), *OutputName);
	Material->Modify();
	In->Connect(OutIndex, Expression);
	return FString();
}
