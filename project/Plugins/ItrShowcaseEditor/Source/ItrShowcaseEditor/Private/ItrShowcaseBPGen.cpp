// ITR Showcase BPGen: JSON spec -> Blueprint (SCS components, member variables, EventGraph of K2 nodes).
// The generated Blueprint only references what the spec names (engine classes/functions); nothing from this module.
#include "ItrShowcaseBPGen.h"

#include "AssetRegistryModule.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"
#include "Dom/JsonObject.h"
#include "EdGraphSchema_K2.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Engine/SCS_Node.h"
#include "Engine/InheritableComponentHandler.h"
#include "K2Node_FunctionEntry.h"
#include "Engine/SimpleConstructionScript.h"
#include "GameFramework/Actor.h"
#include "K2Node_CallArrayFunction.h"
#include "K2Node_CallFunction.h"
#include "K2Node_ClassDynamicCast.h"
#include "K2Node_CreateDelegate.h"
#include "K2Node_Message.h"
#include "K2Node_ComponentBoundEvent.h"
#include "K2Node_CustomEvent.h"
#include "K2Node_DynamicCast.h"
#include "K2Node_Event.h"
#include "K2Node_ExecutionSequence.h"
#include "K2Node_IfThenElse.h"
#include "K2Node_MacroInstance.h"
#include "K2Node_Self.h"
#include "K2Node_VariableGet.h"
#include "K2Node_VariableSet.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/CompilerResultsLog.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Logging/TokenizedMessage.h"
#include "Misc/FileHelper.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "Misc/PackageName.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "Dom/JsonValue.h"
#include "UObject/Package.h"

DEFINE_LOG_CATEGORY_STATIC(LogItrBPGen, Log, All);

namespace ItrBPGen
{
struct FCtx
{
	UBlueprint* BP = nullptr;
	UEdGraph* Graph = nullptr;
	const UEdGraphSchema_K2* Schema = nullptr;
	TMap<FString, UEdGraphNode*> Nodes;
	TArray<FString> Errors;
	TArray<FString> Notes;
	bool bLenient = false;   // spec "lenient": a property that cannot be set is a note ("unreproduced ..."), not an error
	void Err(const FString& S) { Errors.Add(S); UE_LOG(LogItrBPGen, Error, TEXT("%s"), *S); }
	// failure to set one component / CDO property
	void PropFail(const FString& S)
	{
		if (bLenient) { Notes.Add(TEXT("unreproduced ") + S); UE_LOG(LogItrBPGen, Warning, TEXT("unreproduced %s"), *S); }
		else Err(S);
	}
};

// "Actor", "/Script/Engine.Actor", "/Game/Foo/BP_Bar.BP_Bar_C"
static UClass* FindClass(const FString& Name)
{
	if (Name.IsEmpty()) return nullptr;
	if (Name.Contains(TEXT("/")))
	{
		return LoadObject<UClass>(nullptr, *Name);
	}
	UClass* C = FindObject<UClass>(ANY_PACKAGE, *Name);
	if (!C && Name.Len() > 1 && (Name[0] == 'A' || Name[0] == 'U'))
	{
		C = FindObject<UClass>(ANY_PACKAGE, *Name.Mid(1)); // tolerate C++ prefixes: AActor, UGameplayStatics
	}
	if (!C && Name.Len() > 2 && Name[0] == 'I' && FChar::IsUpper(Name[1]))
	{
		C = FindObject<UClass>(ANY_PACKAGE, *Name.Mid(1)); // interface C++ prefix: IVRGripInterface -> VRGripInterface
	}
	return C;
}

static UScriptStruct* FindStruct(const FString& Name)
{
	if (Name.Contains(TEXT("/"))) return LoadObject<UScriptStruct>(nullptr, *Name);
	UScriptStruct* S = FindObject<UScriptStruct>(ANY_PACKAGE, *Name);
	if (!S && Name.Len() > 1 && Name[0] == 'F') S = FindObject<UScriptStruct>(ANY_PACKAGE, *Name.Mid(1));
	return S;
}

// bool|byte|enum:<E>|int|float|name|string|text|vector|rotator|transform|linearcolor|color|struct:<S>|object:<C>|class:<C>|softobject:<C>|softclass:<C>, "[]" suffix = array
static bool ParsePinType(const FString& InType, FEdGraphPinType& Out, FString& Error)
{
	FString T = InType.TrimStartAndEnd();
	Out = FEdGraphPinType();
	if (T.EndsWith(TEXT("[]")))
	{
		Out.ContainerType = EPinContainerType::Array;
		T.LeftChopInline(2);
	}
	FString Kind = T, Arg;
	T.Split(TEXT(":"), &Kind, &Arg);
	if (!T.Contains(TEXT(":"))) { Kind = T; Arg.Empty(); }
	Kind = Kind.ToLower();
	if (Kind == TEXT("bool")) Out.PinCategory = UEdGraphSchema_K2::PC_Boolean;
	else if (Kind == TEXT("byte")) Out.PinCategory = UEdGraphSchema_K2::PC_Byte;
	else if (Kind == TEXT("enum"))
	{
		// a byte variable of a native enum: "enum:/Script/Engine.ESplineMeshAxis"
		Out.PinCategory = UEdGraphSchema_K2::PC_Byte;
		UEnum* E = Arg.StartsWith(TEXT("/")) ? FindObject<UEnum>(nullptr, *Arg) : nullptr;
		if (!E && Arg.StartsWith(TEXT("/"))) E = LoadObject<UEnum>(nullptr, *Arg);
		if (!E) { Error = FString::Printf(TEXT("unknown enum '%s'"), *Arg); return false; }
		Out.PinSubCategoryObject = E;
	}
	else if (Kind == TEXT("int")) Out.PinCategory = UEdGraphSchema_K2::PC_Int;
	else if (Kind == TEXT("float")) Out.PinCategory = UEdGraphSchema_K2::PC_Float;
	else if (Kind == TEXT("name")) Out.PinCategory = UEdGraphSchema_K2::PC_Name;
	else if (Kind == TEXT("string")) Out.PinCategory = UEdGraphSchema_K2::PC_String;
	else if (Kind == TEXT("text")) Out.PinCategory = UEdGraphSchema_K2::PC_Text;
	else if (Kind == TEXT("vector") || Kind == TEXT("rotator") || Kind == TEXT("transform") || Kind == TEXT("linearcolor") || Kind == TEXT("color") || Kind == TEXT("struct"))
	{
		Out.PinCategory = UEdGraphSchema_K2::PC_Struct;
		UScriptStruct* S = nullptr;
		if (Kind == TEXT("vector")) S = TBaseStructure<FVector>::Get();
		else if (Kind == TEXT("rotator")) S = TBaseStructure<FRotator>::Get();
		else if (Kind == TEXT("transform")) S = TBaseStructure<FTransform>::Get();
		else if (Kind == TEXT("linearcolor")) S = TBaseStructure<FLinearColor>::Get();
		else if (Kind == TEXT("color")) S = TBaseStructure<FColor>::Get();
		else S = FindStruct(Arg);
		if (!S) { Error = FString::Printf(TEXT("unknown struct '%s'"), *Arg); return false; }
		Out.PinSubCategoryObject = S;
	}
	else if (Kind == TEXT("object") || Kind == TEXT("class") || Kind == TEXT("softobject") || Kind == TEXT("softclass"))
	{
		Out.PinCategory = Kind == TEXT("object") ? UEdGraphSchema_K2::PC_Object : Kind == TEXT("class") ? UEdGraphSchema_K2::PC_Class
			: Kind == TEXT("softobject") ? UEdGraphSchema_K2::PC_SoftObject : UEdGraphSchema_K2::PC_SoftClass;
		UClass* C = FindClass(Arg);
		if (!C) { Error = FString::Printf(TEXT("unknown class '%s'"), *Arg); return false; }
		Out.PinSubCategoryObject = C;
	}
	else { Error = FString::Printf(TEXT("unknown type '%s'"), *InType); return false; }
	return true;
}

static FString Norm(const FString& S) { return S.Replace(TEXT(" "), TEXT("")).ToLower(); }
// Letters and digits only, lower case: "AsBP Itr Showcase Egg Save" == "AsBP_ItrShowcase_EggSave".
static FString Squash(const FString& S)
{
	FString R;
	for (TCHAR C : S) if (FChar::IsAlnum(C)) R.AppendChar(FChar::ToLower(C));
	return R;
}

// Pin lookup: exact PinName, then case-insensitive, then display/friendly name (e.g. Branch "True"/"False");
// then the aliases exec/in -> execute, out -> then.
static UEdGraphPin* FindPinNamed(UEdGraphNode* Node, const FString& Name, EEdGraphPinDirection Dir)
{
	for (int32 Pass = 0; Pass < 4; ++Pass)
	{
		for (UEdGraphPin* Pin : Node->Pins)
		{
			if (Pin->Direction != Dir) continue;
			const FString PN = Pin->PinName.ToString();
			if (Pass == 0 && PN == Name) return Pin;
			if (Pass == 1 && PN.Equals(Name, ESearchCase::IgnoreCase)) return Pin;
			if (Pass == 2 && (Norm(Pin->PinFriendlyName.ToString()) == Norm(Name) || Norm(Node->GetPinDisplayName(Pin).ToString()) == Norm(Name))) return Pin;
			if (Pass == 3 && (Squash(PN) == Squash(Name) || Squash(Pin->PinFriendlyName.ToString()) == Squash(Name) || Squash(Node->GetPinDisplayName(Pin).ToString()) == Squash(Name))) return Pin;
		}
	}
	return nullptr;
}

static UEdGraphPin* FindPin(UEdGraphNode* Node, const FString& Name, EEdGraphPinDirection Dir)
{
	if (UEdGraphPin* P = FindPinNamed(Node, Name, Dir)) return P;
	if (Dir == EGPD_Input && (Name.Equals(TEXT("exec"), ESearchCase::IgnoreCase) || Name.Equals(TEXT("in"), ESearchCase::IgnoreCase))) return FindPinNamed(Node, TEXT("execute"), Dir);
	if (Dir == EGPD_Output && Name.Equals(TEXT("out"), ESearchCase::IgnoreCase)) return FindPinNamed(Node, TEXT("then"), Dir);
	// Cast nodes name their result pin after the class ("AsFoo"): "as" is the first data output.
	if (Dir == EGPD_Output && Name.Equals(TEXT("as"), ESearchCase::IgnoreCase) && (Cast<UK2Node_DynamicCast>(Node) || Cast<UK2Node_ClassDynamicCast>(Node)))
	{
		for (UEdGraphPin* Pin : Node->Pins)
		{
			if (Pin->Direction == EGPD_Output && Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec && Pin->PinName.ToString() != TEXT("bSuccess")) return Pin;
		}
	}
	return nullptr;
}

static FString PinList(UEdGraphNode* Node)
{
	TArray<FString> L;
	for (UEdGraphPin* Pin : Node->Pins)
	{
		L.Add(FString::Printf(TEXT("%s%s"), Pin->Direction == EGPD_Input ? TEXT("in:") : TEXT("out:"), *Pin->PinName.ToString()));
	}
	return FString::Join(L, TEXT(", "));
}

static FProperty* FindPropCI(const UStruct* S, const FString& Name)
{
	if (FProperty* P = S->FindPropertyByName(FName(*Name))) return P;
	for (TFieldIterator<FProperty> It(S); It; ++It)
	{
		if (It->GetName().Equals(Name, ESearchCase::IgnoreCase)) return *It;
	}
	return nullptr;
}

static UEnum* EnumOf(FProperty* P)
{
	if (FEnumProperty* E = CastField<FEnumProperty>(P)) return E->GetEnum();
	if (FByteProperty* B = CastField<FByteProperty>(P)) return B->Enum;
	return nullptr;
}

static FString FloatText(double D) { return FString::Printf(TEXT("%.9g"), D); }

// JSON value -> the text Prop->ImportText expects, guided by the property's type. Structs are written field by field from the JSON keys
// (a key that is not a UPROPERTY of the struct is skipped and listed in Skipped), arrays as (a,b), enums by name, object references
// by path (loaded first; a missing asset skips the value). bNested = inside struct/array text, where names and strings are quoted.
// Returns false when the value as a whole cannot be expressed.
static bool JsonToText(FProperty* Prop, const TSharedPtr<FJsonValue>& V, bool bNested, FString& Out, TArray<FString>& Skipped)
{
	if (!V.IsValid()) return false;
	if (UEnum* Enum = EnumOf(Prop))
	{
		FString S;
		if (V->TryGetString(S))
		{
			int32 Idx = Enum->GetIndexByName(FName(*S), EGetByNameFlags::CheckAuthoredName);
			FString Short = S;
			int32 Colons = S.Find(TEXT("::"));
			if (Idx == INDEX_NONE && Colons != INDEX_NONE) { Short = S.Mid(Colons + 2); Idx = Enum->GetIndexByName(FName(*Short), EGetByNameFlags::CheckAuthoredName); }
			if (Idx == INDEX_NONE) { Skipped.Add(FString::Printf(TEXT("enum %s has no value '%s'"), *Enum->GetName(), *S)); return false; }
			Out = Short;
			return true;
		}
		double D;
		if (V->TryGetNumber(D)) { Out = FString::Printf(TEXT("%lld"), (int64)D); return true; }
		return false;
	}
	if (CastField<FBoolProperty>(Prop))
	{
		bool B;
		if (V->TryGetBool(B)) { Out = B ? TEXT("True") : TEXT("False"); return true; }
		return false;
	}
	if (FNumericProperty* NumP = CastField<FNumericProperty>(Prop))
	{
		double D;
		if (!V->TryGetNumber(D)) return false;
		Out = NumP->IsFloatingPoint() ? FloatText(D) : FString::Printf(TEXT("%lld"), (int64)D);
		return true;
	}
	if (CastField<FStrProperty>(Prop) || CastField<FNameProperty>(Prop))
	{
		FString S;
		if (!V->TryGetString(S)) return false;
		Out = bNested ? TEXT("\"") + S.ReplaceCharWithEscapedChar() + TEXT("\"") : S;
		return true;
	}
	if (CastField<FTextProperty>(Prop))
	{
		FString S;
		if (V->Type == EJson::Object) V->AsObject()->TryGetStringField(TEXT("CultureInvariantString"), S);
		else V->TryGetString(S);
		Out = TEXT("INVTEXT(\"") + S.ReplaceCharWithEscapedChar() + TEXT("\")");
		return true;
	}
	if (CastField<FSoftObjectProperty>(Prop) && V->Type == EJson::Object)   // CUE4Parse: {"AssetPathName": "/Game/X.X", "SubPathString": ""}
	{
		FString Path = V->AsObject()->GetStringField(TEXT("AssetPathName")), Sub;
		if (V->AsObject()->TryGetStringField(TEXT("SubPathString"), Sub) && !Sub.IsEmpty()) Path += TEXT(":") + Sub;
		Out = (Path.IsEmpty() || Path == TEXT("None")) ? TEXT("None") : (bNested ? TEXT("\"") + Path + TEXT("\"") : Path);
		return true;
	}
	if (CastField<FObjectPropertyBase>(Prop))
	{
		if (V->Type == EJson::Null) { Out = TEXT("None"); return true; }
		FString Path;
		if (!V->TryGetString(Path) || Path.IsEmpty()) return false;
		if (!LoadObject<UObject>(nullptr, *Path, nullptr, LOAD_NoWarn | LOAD_Quiet)) { Skipped.Add(FString::Printf(TEXT("asset '%s' not found in this project"), *Path)); return false; }
		Out = Path;
		return true;
	}
	if (FArrayProperty* AP = CastField<FArrayProperty>(Prop))
	{
		if (V->Type != EJson::Array) return false;
		TArray<FString> Items;
		for (const TSharedPtr<FJsonValue>& E : V->AsArray())
		{
			FString T;
			if (JsonToText(AP->Inner, E, true, T, Skipped)) Items.Add(T);
			else Items.Add(CastField<FObjectPropertyBase>(AP->Inner) ? TEXT("None") : TEXT("")); // keep the slot (OverrideMaterials order)
		}
		Out = TEXT("(") + FString::Join(Items, TEXT(",")) + TEXT(")");
		return true;
	}
	if (FMapProperty* MP = CastField<FMapProperty>(Prop))
	{
		// CUE4Parse: [{"Key": k, "Value": v}, ...]; the text form is ((k,v),(k,v))
		if (V->Type != EJson::Array) return false;
		TArray<FString> Items;
		for (const TSharedPtr<FJsonValue>& E : V->AsArray())
		{
			const TSharedPtr<FJsonObject>* EO = nullptr;
			if (!E->TryGetObject(EO) || !(*EO)->HasField(TEXT("Key")) || !(*EO)->HasField(TEXT("Value"))) return false;
			FString K, Val;
			if (!JsonToText(MP->KeyProp, (*EO)->TryGetField(TEXT("Key")), true, K, Skipped) || !JsonToText(MP->ValueProp, (*EO)->TryGetField(TEXT("Value")), true, Val, Skipped)) return false;
			Items.Add(TEXT("(") + K + TEXT(",") + Val + TEXT(")"));
		}
		Out = TEXT("(") + FString::Join(Items, TEXT(",")) + TEXT(")");
		return true;
	}
	if (FStructProperty* SP = CastField<FStructProperty>(Prop))
	{
		const FString SN = SP->Struct->GetName();
		if (SN == TEXT("GameplayTagContainer") && V->Type == EJson::Array)
		{
			TArray<FString> Tags;
			for (const TSharedPtr<FJsonValue>& E : V->AsArray()) { FString S; if (E->TryGetString(S)) Tags.Add(TEXT("(TagName=\"") + S + TEXT("\")")); }
			Out = TEXT("(GameplayTags=(") + FString::Join(Tags, TEXT(",")) + TEXT("))");
			return true;
		}
		if (SN == TEXT("GameplayTag") && V->Type == EJson::String) { Out = TEXT("(TagName=\"") + V->AsString() + TEXT("\")"); return true; }
		if (SN == TEXT("Guid") && V->Type == EJson::String)   // CUE4Parse prints FGuid as "XXXXXXXX-XXXXXXXX-XXXXXXXX-XXXXXXXX"
		{
			FGuid G;
			if (!FGuid::Parse(V->AsString().Replace(TEXT("-"), TEXT("")), G)) return false;
			Out = G.ToString(EGuidFormats::Digits);
			return true;
		}
		if (V->Type != EJson::Object) return false;
		TArray<FString> Parts;
		for (const auto& KV : V->AsObject()->Values)
		{
			if (KV.Key == TEXT("Hex")) continue; // FColor dump helper field, not a UPROPERTY
			FProperty* F = FindPropCI(SP->Struct, KV.Key);
			if (!F) { Skipped.Add(FString::Printf(TEXT("%s has no field '%s'"), *SN, *KV.Key)); continue; }
			FString T;
			// an empty array stays out of the text: UE's array ImportText turns "()" into one default element; the struct starts empty anyway
			if (KV.Value->Type == EJson::Array && KV.Value->AsArray().Num() == 0 && CastField<FArrayProperty>(F)) continue;
			if (JsonToText(F, KV.Value, true, T, Skipped)) Parts.Add(F->GetName() + TEXT("=") + T);
			else Skipped.Add(FString::Printf(TEXT("%s.%s value dropped"), *SN, *F->GetName()));
		}
		Out = TEXT("(") + FString::Join(Parts, TEXT(",")) + TEXT(")");
		return true;
	}
	Skipped.Add(FString::Printf(TEXT("unsupported property type %s"), *Prop->GetClass()->GetName()));
	return false;
}

// Sets one property from a spec value: a JSON string is T3D text (or an object path), anything else goes through JsonToText.
static bool ApplyProp(UObject* Obj, const FString& Key, const TSharedPtr<FJsonValue>& Val, FCtx& Ctx, const FString& Where)
{
	FProperty* Prop = FindPropCI(Obj->GetClass(), Key);
	if (!Prop) { Ctx.PropFail(FString::Printf(TEXT("%s.%s: no such property on %s"), *Where, *Key, *Obj->GetClass()->GetName())); return false; }
	void* Data = Prop->ContainerPtrToValuePtr<void>(Obj);
	FString Text;
	TArray<FString> Skipped;
	FString S;
	bool bOk = false;
	if (Val->Type == EJson::String && Val->TryGetString(S))
	{
		if (CastField<FObjectPropertyBase>(Prop) && S.StartsWith(TEXT("/")))
		{
			UObject* O = LoadObject<UObject>(nullptr, *S, nullptr, LOAD_NoWarn | LOAD_Quiet);
			if (!O) { Ctx.PropFail(FString::Printf(TEXT("%s.%s: asset '%s' not found in this project"), *Where, *Key, *S)); return false; }
			CastField<FObjectPropertyBase>(Prop)->SetObjectPropertyValue(Data, O);
			return true;
		}
		if (EnumOf(Prop) || CastField<FStructProperty>(Prop)) { bOk = JsonToText(Prop, Val, false, Text, Skipped); }   // enum names, FGuid strings
		else { Text = S; bOk = true; }
	}
	else if (Val->Type == EJson::Number || Val->Type == EJson::Boolean || Val->Type == EJson::Object || Val->Type == EJson::Array || Val->Type == EJson::Null)
	{
		if (FObjectPropertyBase* OP = CastField<FObjectPropertyBase>(Prop))
		{
			if (Val->Type == EJson::Null) { OP->SetObjectPropertyValue(Data, nullptr); return true; }
		}
		if (FArrayProperty* AP = CastField<FArrayProperty>(Prop))
		{
			if (Val->Type == EJson::Array && Val->AsArray().Num() == 0) { FScriptArrayHelper(AP, Data).EmptyValues(); return true; }   // "()" would import one element
		}
		bOk = JsonToText(Prop, Val, false, Text, Skipped);
	}
	if (!bOk)
	{
		Ctx.PropFail(FString::Printf(TEXT("%s.%s: cannot express the value for a %s%s"), *Where, *Key, *Prop->GetClass()->GetName(), Skipped.Num() ? *(TEXT(" (") + FString::Join(Skipped, TEXT("; ")) + TEXT(")")) : TEXT("")));
		return false;
	}
	if (!Prop->ImportText(*Text, Data, PPF_None, Obj))
	{
		Ctx.PropFail(FString::Printf(TEXT("%s.%s: could not import '%s'"), *Where, *Key, *Text.Left(200)));
		return false;
	}
	for (const FString& Sk : Skipped) Ctx.Notes.Add(FString::Printf(TEXT("unreproduced part of %s.%s: %s"), *Where, *Key, *Sk));
	return true;
}

static bool ImportProps(UObject* Obj, const TSharedPtr<FJsonObject>& Props, FCtx& Ctx, const FString& Where)
{
	if (!Props.IsValid()) return true;
	bool bOk = true;
	for (const auto& KV : Props->Values)
	{
		// structured values (objects, arrays, null) and strings for lenient specs: converted by property type, see ApplyProp
		if (KV.Value->Type == EJson::Object || KV.Value->Type == EJson::Array || KV.Value->Type == EJson::Null || Ctx.bLenient)
		{
			if (!ApplyProp(Obj, KV.Key, KV.Value, Ctx, Where)) bOk = false;
			continue;
		}
		FProperty* Prop = FindPropCI(Obj->GetClass(), KV.Key);
		if (!Prop) { Ctx.Err(FString::Printf(TEXT("%s: no property '%s' on %s"), *Where, *KV.Key, *Obj->GetClass()->GetName())); bOk = false; continue; }
		FString V;
		if (!KV.Value->TryGetString(V))
		{
			double D; bool B;
			if (KV.Value->TryGetNumber(D)) V = (D == FMath::FloorToDouble(D) && FMath::Abs(D) < 1e9) ? FString::Printf(TEXT("%lld"), (int64)D) : FString::SanitizeFloat(D);
			else if (KV.Value->TryGetBool(B)) V = B ? TEXT("True") : TEXT("False");
		}
		void* Data = Prop->ContainerPtrToValuePtr<void>(Obj);
		if (FObjectPropertyBase* OP = CastField<FObjectPropertyBase>(Prop))
		{
			if (V.StartsWith(TEXT("/")))
			{
				UObject* O = LoadObject<UObject>(nullptr, *V);
				if (!O) { Ctx.Err(FString::Printf(TEXT("%s: cannot load '%s' for %s"), *Where, *V, *KV.Key)); bOk = false; continue; }
				OP->SetObjectPropertyValue(Data, O);
				continue;
			}
		}
		if (!Prop->ImportText(*V, Data, PPF_None, Obj))
		{
			Ctx.Err(FString::Printf(TEXT("%s: could not import '%s' into %s"), *Where, *V, *KV.Key)); bOk = false;
		}
	}
	return bOk;
}

template <typename T>
static T* NewNode(FCtx& Ctx, TFunctionRef<void(T*)> Setup)
{
	FGraphNodeCreator<T> Creator(*Ctx.Graph);
	T* N = Creator.CreateNode(false);
	Setup(N);
	Creator.Finalize();
	return N;
}

static UEdGraphNode* MakeNode(FCtx& Ctx, const TSharedPtr<FJsonObject>& J, const FString& Id)
{
	const FString Op = J->GetStringField(TEXT("op"));
	UBlueprint* BP = Ctx.BP;
	auto Str = [&J](const TCHAR* F) { FString S; J->TryGetStringField(F, S); return S; };

	if (Op == TEXT("event"))
	{
		const FName EvName(*Str(TEXT("event")));
		UClass* EvClass = J->HasField(TEXT("class")) ? FindClass(Str(TEXT("class"))) : BP->ParentClass.Get();
		UFunction* F = EvClass ? EvClass->FindFunctionByName(EvName) : nullptr;
		if (!F) { Ctx.Err(FString::Printf(TEXT("%s: no event '%s'"), *Id, *EvName.ToString())); return nullptr; }
		UClass* Owner = F->GetOwnerClass();
		return NewNode<UK2Node_Event>(Ctx, [&](UK2Node_Event* N) { N->EventReference.SetExternalMember(EvName, Owner); N->bOverrideFunction = true; });
	}
	if (Op == TEXT("custom_event"))
	{
		const FName EvName(*Str(TEXT("name")));
		UK2Node_CustomEvent* CE = NewNode<UK2Node_CustomEvent>(Ctx, [&](UK2Node_CustomEvent* N) { N->CustomFunctionName = EvName; N->bIsEditable = true; });
		// "params": [{"name": "Stage", "type": "int"}]: event parameters (output pins of the event, input pins of the call nodes).
		const TArray<TSharedPtr<FJsonValue>>* EvParams = nullptr;
		if (J->TryGetArrayField(TEXT("params"), EvParams))
		{
			for (const TSharedPtr<FJsonValue>& PV : *EvParams)
			{
				const TSharedPtr<FJsonObject> PO = PV->AsObject();
				FEdGraphPinType PT; FString TypeErr;
				if (!PO.IsValid() || !ParsePinType(PO->GetStringField(TEXT("type")), PT, TypeErr)) { Ctx.Err(FString::Printf(TEXT("%s: bad event param (%s)"), *Id, *TypeErr)); continue; }
				CE->CreateUserDefinedPin(FName(*PO->GetStringField(TEXT("name"))), PT, EGPD_Output);
			}
		}
		return CE;
	}
	if (Op == TEXT("component_event"))
	{
		const FString Comp = Str(TEXT("component")), Del = Str(TEXT("delegate"));
		FObjectProperty* CP = FindFProperty<FObjectProperty>(BP->SkeletonGeneratedClass, FName(*Comp));
		FMulticastDelegateProperty* DP = CP ? FindFProperty<FMulticastDelegateProperty>(CP->PropertyClass, FName(*Del)) : nullptr;
		if (!CP || !DP) { Ctx.Err(FString::Printf(TEXT("%s: component '%s' / delegate '%s' not found"), *Id, *Comp, *Del)); return nullptr; }
		return NewNode<UK2Node_ComponentBoundEvent>(Ctx, [&](UK2Node_ComponentBoundEvent* N) { N->InitializeComponentBoundEventParams(CP, DP); });
	}
	if (Op == TEXT("call"))
	{
		FString Func = Str(TEXT("function")), ClassName;
		if (Func.Contains(TEXT(":"))) Func.Split(TEXT(":"), &ClassName, &Func, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		UClass* C = ClassName.IsEmpty() ? BP->SkeletonGeneratedClass : FindClass(ClassName);
		UFunction* F = C ? C->FindFunctionByName(FName(*Func)) : nullptr;
		if (!F) { Ctx.Err(FString::Printf(TEXT("%s: function '%s' not found on '%s'"), *Id, *Func, *ClassName)); return nullptr; }
		if (F->HasMetaData(FBlueprintMetadata::MD_ArrayParam))
		{
			return NewNode<UK2Node_CallArrayFunction>(Ctx, [&](UK2Node_CallArrayFunction* N) { N->SetFromFunction(F); });
		}
		return NewNode<UK2Node_CallFunction>(Ctx, [&](UK2Node_CallFunction* N) { N->SetFromFunction(F); });
	}
	if (Op == TEXT("message"))
	{
		// Interface function called on any object reference (K2Node_Message: "(Message)" call; does nothing when the object lacks the interface).
		FString Func = Str(TEXT("function")), ClassName;
		if (Func.Contains(TEXT(":"))) Func.Split(TEXT(":"), &ClassName, &Func, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		UClass* C = FindClass(ClassName);
		UFunction* F = C ? C->FindFunctionByName(FName(*Func)) : nullptr;
		if (!F || !C->HasAnyClassFlags(CLASS_Interface)) { Ctx.Err(FString::Printf(TEXT("%s: interface function '%s' not found on '%s'"), *Id, *Func, *ClassName)); return nullptr; }
		return NewNode<UK2Node_Message>(Ctx, [&](UK2Node_Message* N) { N->SetFromFunction(F); });
	}
	if (Op == TEXT("create_delegate"))
	{
		// Bound after the links are made (the signature comes from the delegate pin it is linked to): see PostLink in GenerateBlueprintFromSpec.
		return NewNode<UK2Node_CreateDelegate>(Ctx, [](UK2Node_CreateDelegate*) {});
	}
	if (Op == TEXT("get") || Op == TEXT("set"))
	{
		const FName Var(*Str(TEXT("var")));
		UClass* Ext = J->HasField(TEXT("class")) ? FindClass(Str(TEXT("class"))) : nullptr;
		auto Ref = [&](FMemberReference& R) { if (Ext) R.SetExternalMember(Var, Ext); else R.SetSelfMember(Var); };
		if (!Ext && !FindFProperty<FProperty>(BP->SkeletonGeneratedClass, Var)) { Ctx.Err(FString::Printf(TEXT("%s: no variable '%s'"), *Id, *Var.ToString())); return nullptr; }
		if (Op == TEXT("get")) return NewNode<UK2Node_VariableGet>(Ctx, [&](UK2Node_VariableGet* N) { Ref(N->VariableReference); });
		return NewNode<UK2Node_VariableSet>(Ctx, [&](UK2Node_VariableSet* N) { Ref(N->VariableReference); });
	}
	if (Op == TEXT("branch")) return NewNode<UK2Node_IfThenElse>(Ctx, [](UK2Node_IfThenElse*) {});
	if (Op == TEXT("self")) return NewNode<UK2Node_Self>(Ctx, [](UK2Node_Self*) {});
	if (Op == TEXT("sequence"))
	{
		UK2Node_ExecutionSequence* N = NewNode<UK2Node_ExecutionSequence>(Ctx, [](UK2Node_ExecutionSequence*) {});
		int32 Outs = 2; J->TryGetNumberField(TEXT("outputs"), Outs);
		for (int32 i = 2; i < Outs; ++i) N->AddInputPin();
		return N;
	}
	if (Op == TEXT("cast"))
	{
		UClass* C = FindClass(Str(TEXT("class")));
		if (!C) { Ctx.Err(FString::Printf(TEXT("%s: unknown cast class"), *Id)); return nullptr; }
		bool bPure = false; J->TryGetBoolField(TEXT("pure"), bPure);
		bool bClassCast = false; J->TryGetBoolField(TEXT("class_cast"), bClassCast); // "Cast To <C> Class": converts a class reference (pins Class -> As <C>)
		if (bClassCast) return NewNode<UK2Node_ClassDynamicCast>(Ctx, [&](UK2Node_ClassDynamicCast* N) { N->TargetType = C; });
		return NewNode<UK2Node_DynamicCast>(Ctx, [&](UK2Node_DynamicCast* N) { N->TargetType = C; if (bPure) N->SetPurity(true); });
	}
	if (Op == TEXT("macro"))
	{
		FString Lib = TEXT("/Engine/EditorBlueprintResources/StandardMacros.StandardMacros");
		J->TryGetStringField(TEXT("library"), Lib);
		UBlueprint* MacroBP = LoadObject<UBlueprint>(nullptr, *Lib);
		const FString MacroName = Str(TEXT("macro"));
		UEdGraph* MG = nullptr;
		if (MacroBP) for (UEdGraph* G : MacroBP->MacroGraphs) if (G && G->GetName() == MacroName) MG = G;
		if (!MG) { Ctx.Err(FString::Printf(TEXT("%s: macro '%s' not found in %s"), *Id, *MacroName, *Lib)); return nullptr; }
		return NewNode<UK2Node_MacroInstance>(Ctx, [&](UK2Node_MacroInstance* N) { N->SetMacroGraph(MG); });
	}
	if (Op == TEXT("node"))
	{
		// Escape hatch: any K2 node class, configured through its UPROPERTYs (T3D text values) before pins are made.
		UClass* C = FindClass(Str(TEXT("class")));
		if (!C || !C->IsChildOf(UEdGraphNode::StaticClass())) { Ctx.Err(FString::Printf(TEXT("%s: unknown node class"), *Id)); return nullptr; }
		UEdGraphNode* N = NewObject<UEdGraphNode>(Ctx.Graph, C, NAME_None, RF_Transactional);
		Ctx.Graph->AddNode(N, false, false);
		N->CreateNewGuid();
		const TSharedPtr<FJsonObject>* P = nullptr;
		if (J->TryGetObjectField(TEXT("props"), P)) ImportProps(N, *P, Ctx, Id);
		N->PostPlacedNewNode();
		N->AllocateDefaultPins();
		return N;
	}
	Ctx.Err(FString::Printf(TEXT("%s: unknown op '%s'"), *Id, *Op));
	return nullptr;
}

static void SetPinDefault(FCtx& Ctx, UEdGraphNode* N, const FString& Id, const FString& PinName, const FString& V)
{
	UEdGraphPin* Pin = FindPin(N, PinName, EGPD_Input);
	if (!Pin) { Ctx.Err(FString::Printf(TEXT("%s: no input pin '%s' (pins: %s)"), *Id, *PinName, *PinList(N))); return; }
	const FName Cat = Pin->PinType.PinCategory;
	if ((Cat == UEdGraphSchema_K2::PC_Object || Cat == UEdGraphSchema_K2::PC_Class || Cat == UEdGraphSchema_K2::PC_SoftObject || Cat == UEdGraphSchema_K2::PC_SoftClass) && V.StartsWith(TEXT("/")))
	{
		if (Cat == UEdGraphSchema_K2::PC_SoftObject || Cat == UEdGraphSchema_K2::PC_SoftClass)
		{
			// Soft references are only a path: the asset (e.g. one of the game's) need not exist in this project.
			Pin->DefaultValue = V;
			return;
		}
		UObject* O = LoadObject<UObject>(nullptr, *V);
		if (!O) { Ctx.Err(FString::Printf(TEXT("%s.%s: cannot load '%s'"), *Id, *PinName, *V)); return; }
		Ctx.Schema->TrySetDefaultObject(*Pin, O);
	}
	else if (Cat == UEdGraphSchema_K2::PC_Text)
	{
		Ctx.Schema->TrySetDefaultText(*Pin, FText::FromString(V));
	}
	else
	{
		Ctx.Schema->TrySetDefaultValue(*Pin, V);
	}
	const FString Bad = Ctx.Schema->IsPinDefaultValid(Pin, Pin->DefaultValue, Pin->DefaultObject, Pin->DefaultTextValue);
	if (!Bad.IsEmpty()) Ctx.Err(FString::Printf(TEXT("%s.%s = '%s': %s"), *Id, *PinName, *V, *Bad));
}

static bool SplitPinRef(const FString& Ref, FString& Id, FString& Pin)
{
	return Ref.Split(TEXT("."), &Id, &Pin);
}

// Remove everything a previous run generated, keeping the asset (and placed instances) intact.
// SCS node named Name in the Blueprint parent chain of BP (components a parent Blueprint defines)
static USCS_Node* FindInheritedNode(UBlueprint* BP, const FString& Name)
{
	for (UClass* C = BP->ParentClass; C; C = C->GetSuperClass())
	{
		UBlueprintGeneratedClass* G = Cast<UBlueprintGeneratedClass>(C);
		if (!G || !G->SimpleConstructionScript) continue;
		for (USCS_Node* N : G->SimpleConstructionScript->GetAllNodes())
			if (N && N->GetVariableName().ToString() == Name) return N;
	}
	return nullptr;
}

// scene component named Name that the native part of class C creates (on its class default object)
static USceneComponent* FindNativeComponent(UClass* C, const FString& Name)
{
	AActor* CDO = C ? Cast<AActor>(C->GetDefaultObject()) : nullptr;
	if (!CDO) return nullptr;
	TInlineComponentArray<USceneComponent*> Comps;
	CDO->GetComponents(Comps);
	for (USceneComponent* SC : Comps) if (SC && SC->GetName() == Name) return SC;
	return nullptr;
}

static void ResetBlueprint(UBlueprint* BP)
{
	for (UEdGraph* G : BP->UbergraphPages)
	{
		TArray<UEdGraphNode*> Old = G->Nodes;
		for (UEdGraphNode* N : Old) FBlueprintEditorUtils::RemoveNode(BP, N, true);
	}
	if (USimpleConstructionScript* SCS = BP->SimpleConstructionScript)
	{
		TArray<USCS_Node*> All = SCS->GetAllNodes();
		for (int32 i = All.Num() - 1; i >= 0; --i)
		{
			if (All[i] && All[i] != SCS->GetDefaultSceneRootNode()) SCS->RemoveNode(All[i], false);
		}
		SCS->ValidateSceneRootNodes();
	}
	TArray<FName> Vars;
	for (const FBPVariableDescription& V : BP->NewVariables) Vars.Add(V.VarName);
	for (const FName& V : Vars) FBlueprintEditorUtils::RemoveMemberVariable(BP, V);
}

static FString CompileAndReport(FCtx& Ctx, TArray<FString>& Lines)
{
	FCompilerResultsLog Results;
	Results.SetSourcePath(Ctx.BP->GetPathName());
	Results.bSilentMode = false;
	FKismetEditorUtilities::CompileBlueprint(Ctx.BP, EBlueprintCompileOptions::SkipGarbageCollection, &Results);
	TSet<FString> Seen;
	int32 NumWarn = 0;
	for (const TSharedRef<FTokenizedMessage>& M : Results.Messages)
	{
		const EMessageSeverity::Type S = M->GetSeverity();
		const bool bErr = S == EMessageSeverity::Error || S == EMessageSeverity::CriticalError;
		const bool bWarn = S == EMessageSeverity::Warning || S == EMessageSeverity::PerformanceWarning;
		const FString Msg = M->ToText().ToString();
		if ((!bErr && !bWarn) || Seen.Contains(Msg)) continue; // notes ("Compile of X successful") are noise
		Seen.Add(Msg);
		Lines.Add(FString::Printf(TEXT("  compile %s: %s"), bErr ? TEXT("error") : TEXT("warning"), *Msg));
		if (bErr) Ctx.Errors.Add(Msg); else ++NumWarn;
	}
	Lines.Insert(FString::Printf(TEXT("  compile: %d errors, %d warnings, status %s"), Results.NumErrors, NumWarn,
		Ctx.BP->Status == BS_UpToDate ? TEXT("UpToDate") : Ctx.BP->Status == BS_UpToDateWithWarnings ? TEXT("UpToDateWithWarnings") : Ctx.BP->Status == BS_Error ? TEXT("Error") : TEXT("Dirty/Unknown")), 0);
	if (Ctx.BP->Status == BS_Error && Results.NumErrors == 0) Ctx.Errors.Add(TEXT("blueprint status is BS_Error"));
	return FString();
}

// Specs generated in this process (full path -> file time), so a "requires" chain generates each spec once per spec edit.
static TMap<FString, FDateTime> GGenerated;
static FString SpecKey(const FString& Path)
{
	FString K = FPaths::ConvertRelativePathToFull(Path);
	FPaths::NormalizeFilename(K);
	return K.ToLower();
}
} // namespace ItrBPGen

// Bridge for ItrShowcaseAudit.cpp: the spec type parser
bool ItrBPGenParsePinType(const FString& Type, FEdGraphPinType& Out, FString& Error) { return ItrBPGen::ParsePinType(Type, Out, Error); }

// Bridge for ItrShowcaseAudit.cpp: sets one property of Obj from a JSON value with the generator's converter (strict: every value or struct
// field that cannot be set is returned in OutProblems). Key may name a static-array element as "Name[3]".
bool ItrBPGenApplyJsonProp(UObject* Obj, const FString& Key, const TSharedPtr<FJsonValue>& Val, TArray<FString>& OutProblems)
{
	using namespace ItrBPGen;
	FString Base = Key; int32 Index = 0;
	int32 Br = INDEX_NONE;
	if (Key.EndsWith(TEXT("]")) && Key.FindChar(TEXT('['), Br))
	{
		Base = Key.Left(Br);
		Index = FCString::Atoi(*Key.Mid(Br + 1));
		FProperty* Prop = FindPropCI(Obj->GetClass(), Base);
		if (!Prop || Index < 0 || Index >= Prop->ArrayDim) { OutProblems.Add(FString::Printf(TEXT("%s: no static array element %s on %s"), *Obj->GetName(), *Key, *Obj->GetClass()->GetName())); return false; }
		FString Text; TArray<FString> Skipped;
		if (!JsonToText(Prop, Val, false, Text, Skipped) || !Prop->ImportText(*Text, Prop->ContainerPtrToValuePtr<void>(Obj, Index), PPF_None, Obj))
		{
			OutProblems.Add(FString::Printf(TEXT("%s.%s: cannot set (%s)"), *Obj->GetName(), *Key, *FString::Join(Skipped, TEXT("; "))));
			return false;
		}
		for (const FString& S : Skipped) OutProblems.Add(FString::Printf(TEXT("%s.%s: %s"), *Obj->GetName(), *Key, *S));
		return Skipped.Num() == 0;
	}
	FCtx Ctx;
	Ctx.bLenient = true;   // failures land in Notes ("unreproduced ...") instead of being logged as errors; all of them are returned
	const bool bOk = ApplyProp(Obj, Key, Val, Ctx, Obj->GetName());
	OutProblems.Append(Ctx.Errors);
	OutProblems.Append(Ctx.Notes);
	return bOk && Ctx.Errors.Num() == 0 && Ctx.Notes.Num() == 0;
}

FString UItrShowcaseBPGen::GenerateBlueprintFromSpec(const FString& JsonPath)
{
	using namespace ItrBPGen;
	FString Text;
	if (!FFileHelper::LoadFileToString(Text, *JsonPath)) return FString::Printf(TEXT("ERROR cannot read %s"), *JsonPath);
	TSharedPtr<FJsonObject> Spec;
	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(Text), Spec) || !Spec.IsValid()) return FString::Printf(TEXT("ERROR bad JSON in %s"), *JsonPath);

	// "requires": ["Other.json", ...] (paths relative to this spec): generated first, so that this Blueprint can reference their classes.
	const FString Key = SpecKey(JsonPath);
	const FDateTime FileTime = IFileManager::Get().GetTimeStamp(*JsonPath);
	if (const FDateTime* Done = GGenerated.Find(Key)) { if (*Done == FileTime) return FString::Printf(TEXT("OK %s (already generated in this session)"), *Spec->GetStringField(TEXT("asset"))); }
	const TArray<TSharedPtr<FJsonValue>>* Requires = nullptr;
	if (Spec->TryGetArrayField(TEXT("requires"), Requires))
	{
		for (const TSharedPtr<FJsonValue>& R : *Requires)
		{
			const FString Dep = FPaths::Combine(FPaths::GetPath(JsonPath), R->AsString());
			const FString DepReport = GenerateBlueprintFromSpec(Dep);
			if (!DepReport.StartsWith(TEXT("OK"))) return FString::Printf(TEXT("ERROR %s: required spec %s failed:\n%s"), *Spec->GetStringField(TEXT("asset")), *Dep, *DepReport);
		}
	}

	FCtx Ctx;
	TArray<FString> Lines;
	Spec->TryGetBoolField(TEXT("lenient"), Ctx.bLenient);
	const FString Asset =Spec->GetStringField(TEXT("asset")); // /Game/Mods/X/BP_Name
	const FString AssetName = FPackageName::GetLongPackageAssetName(Asset);
	FString ParentName = TEXT("/Script/Engine.Actor");
	Spec->TryGetStringField(TEXT("parent"), ParentName);
	UClass* Parent = FindClass(ParentName);
	if (!Parent) return FString::Printf(TEXT("ERROR %s: unknown parent class %s"), *Asset, *ParentName);

	// 1. Asset: create, or reset in place (keeps references from placed instances valid).
	UPackage* Pkg = CreatePackage(*Asset);
	Pkg->FullyLoad();
	UBlueprint* BP = FindObject<UBlueprint>(Pkg, *AssetName);
	if (!BP) BP = LoadObject<UBlueprint>(nullptr, *(Asset + TEXT(".") + AssetName), nullptr, LOAD_NoWarn | LOAD_Quiet);
	const bool bNew = (BP == nullptr);
	if (bNew)
	{
		BP = FKismetEditorUtilities::CreateBlueprint(Parent, Pkg, FName(*AssetName), BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), FName("ItrShowcaseBPGen"));
		if (!BP) return FString::Printf(TEXT("ERROR %s: CreateBlueprint failed"), *Asset);
	}
	else
	{
		if (BP->ParentClass != Parent) { BP->ParentClass = Parent; }
		ResetBlueprint(BP);
	}
	Ctx.BP = BP;
	Ctx.Schema = GetDefault<UEdGraphSchema_K2>();
	Ctx.Graph = FBlueprintEditorUtils::FindEventGraph(BP);
	const TArray<TSharedPtr<FJsonValue>>* NodeArr = nullptr;
	const bool bHasNodes = Spec->TryGetArrayField(TEXT("nodes"), NodeArr) && NodeArr->Num() > 0;
	if (!Ctx.Graph && bHasNodes) return FString::Printf(TEXT("ERROR %s: no EventGraph (parent %s)"), *Asset, *Parent->GetName());
	if (bNew && Ctx.Graph)
	{
		TArray<UEdGraphNode*> Ghosts = Ctx.Graph->Nodes; // default (ghost) BeginPlay/Tick/ActorBeginOverlap
		for (UEdGraphNode* N : Ghosts) FBlueprintEditorUtils::RemoveNode(BP, N, true);
	}

	// 2. Components (SCS). The first parentless scene component becomes the root.
	const TArray<TSharedPtr<FJsonValue>>* Comps = nullptr;
	// A non-actor Blueprint (an ActorComponent / object Blueprint, e.g. BPC_DamageOverTime) has no SimpleConstructionScript: nothing to build.
	if (Spec->TryGetArrayField(TEXT("components"), Comps) && !BP->SimpleConstructionScript && Comps->Num() > 0)
		Ctx.Err(FString::Printf(TEXT("%s: components listed but the parent class %s has no SimpleConstructionScript"), *Asset, *Parent->GetName()));
	if (Comps && BP->SimpleConstructionScript)
	{
		USimpleConstructionScript* SCS = BP->SimpleConstructionScript;
		TMap<FString, USCS_Node*> ByName;
		// A spec with its own parentless scene component replaces DefaultSceneRoot (otherwise both stay root nodes).
		for (const TSharedPtr<FJsonValue>& V : *Comps)
		{
			UClass* CC = FindClass(V->AsObject()->GetStringField(TEXT("class")));
			if (CC && CC->IsChildOf(USceneComponent::StaticClass()) && !V->AsObject()->HasField(TEXT("attach")) && SCS->GetDefaultSceneRootNode()
				&& V->AsObject()->GetStringField(TEXT("name")) != TEXT("DefaultSceneRoot"))
			{
				SCS->RemoveNode(SCS->GetDefaultSceneRootNode(), false);
				break;
			}
		}
		for (const TSharedPtr<FJsonValue>& V : *Comps)
		{
			const TSharedPtr<FJsonObject> C = V->AsObject();
			const FString Name = C->GetStringField(TEXT("name"));
			UClass* CC = FindClass(C->GetStringField(TEXT("class")));
			if (!CC || !CC->IsChildOf(UActorComponent::StaticClass())) { Ctx.Err(FString::Printf(TEXT("component %s: bad class"), *Name)); continue; }
			USCS_Node* Node = nullptr;
			if (Name == TEXT("DefaultSceneRoot") && !C->HasField(TEXT("attach")))
			{
				// the SCS's own default scene root (the game's Blueprint lists it; with a native root it stays unused): keep it, do not add one
				if (USCS_Node* Def = SCS->GetDefaultSceneRootNode())
				{
					FString GuidStr; FGuid NodeGuid;
					if (C->TryGetStringField(TEXT("guid"), GuidStr) && FGuid::Parse(GuidStr, NodeGuid)) Def->VariableGuid = NodeGuid;
					const TSharedPtr<FJsonObject>* P0 = nullptr;
					if (C->TryGetObjectField(TEXT("props"), P0) && (*P0)->Values.Num()) ImportProps(Def->ComponentTemplate, *P0, Ctx, TEXT("component ") + Name);
					ByName.Add(Name, Def);
				}
				continue;
			}
			Node = SCS->CreateNode(CC, FName(*Name));
			if (Node->GetVariableName() != FName(*Name)) Node->SetVariableName(FName(*Name), true);   // e.g. "DefaultSceneRoot", reserved by CreateNode
			// the game's node GUID (T-116): child Blueprints key their component overrides by it, so a parent regenerated after its children
			// must keep it, or every child override is orphaned and the parent's template shows through (the carpet showed the fire shield)
			FString GuidStr; FGuid NodeGuid;
			if (C->TryGetStringField(TEXT("guid"), GuidStr) && FGuid::Parse(GuidStr, NodeGuid)) Node->VariableGuid = NodeGuid;
			else if (C->HasField(TEXT("guid"))) Ctx.Err(FString::Printf(TEXT("component %s: bad guid '%s'"), *Name, *GuidStr));
			FString ParentComp;
			USCS_Node* Inherited = nullptr;
			if (C->TryGetStringField(TEXT("attach"), ParentComp) && ByName.Contains(ParentComp) && ByName[ParentComp]) ByName[ParentComp]->AddChildNode(Node);
			else if (!ParentComp.IsEmpty() && (Inherited = FindInheritedNode(BP, ParentComp)) != nullptr)
			{
				Node->SetParent(Inherited);   // a component of a parent Blueprint (T-116: chains are recreated level by level)
				SCS->AddNode(Node);
			}
			else if (!ParentComp.IsEmpty() && FindNativeComponent(Parent, ParentComp))
			{
				Node->SetParent(FindNativeComponent(Parent, ParentComp));   // a component the native parent class creates
				SCS->AddNode(Node);
				Inherited = Node;
			}
			else SCS->AddNode(Node);
			ByName.Add(Name, Node);
			FString Socket;
			if (C->TryGetStringField(TEXT("socket"), Socket) && !Socket.IsEmpty()) Node->AttachToName = FName(*Socket);
			if (!ParentComp.IsEmpty() && !ByName.Contains(ParentComp) && !Inherited) Ctx.Err(FString::Printf(TEXT("component %s: attach parent '%s' is not defined before it"), *Name, *ParentComp));
			const TSharedPtr<FJsonObject>* P = nullptr;
			if (C->TryGetObjectField(TEXT("props"), P)) ImportProps(Node->ComponentTemplate, *P, Ctx, TEXT("component ") + Name);
		}
		SCS->ValidateSceneRootNodes();
	}

	// 3. Member variables.
	const TArray<TSharedPtr<FJsonValue>>* Vars = nullptr;
	if (Spec->TryGetArrayField(TEXT("variables"), Vars))
	{
		for (const TSharedPtr<FJsonValue>& V : *Vars)
		{
			const TSharedPtr<FJsonObject> O = V->AsObject();
			const FName Name(*O->GetStringField(TEXT("name")));
			FEdGraphPinType PT; FString TypeErr;
			if (!ParsePinType(O->GetStringField(TEXT("type")), PT, TypeErr)) { Ctx.Err(FString::Printf(TEXT("variable %s: %s"), *Name.ToString(), *TypeErr)); continue; }
			FString Def; O->TryGetStringField(TEXT("default"), Def);
			if (!FBlueprintEditorUtils::AddMemberVariable(BP, Name, PT, Def)) { Ctx.Err(FString::Printf(TEXT("variable %s: AddMemberVariable failed"), *Name.ToString())); continue; }
			bool bEditable = false; O->TryGetBoolField(TEXT("editable"), bEditable);
			FBlueprintEditorUtils::SetBlueprintOnlyEditableFlag(BP, Name, !bEditable);
			FString S;
			if (O->TryGetStringField(TEXT("category"), S)) FBlueprintEditorUtils::SetBlueprintVariableCategory(BP, Name, nullptr, FText::FromString(S));
			if (O->TryGetStringField(TEXT("tooltip"), S)) FBlueprintEditorUtils::SetBlueprintVariableMetaData(BP, Name, nullptr, TEXT("tooltip"), S);
		}
	}

	// 3b. Event dispatchers ("dispatchers": [{"name": "StashOpened"}]): member multicast delegate + its signature graph (no parameters).
	const TArray<TSharedPtr<FJsonValue>>* Disp = nullptr;
	if (Spec->TryGetArrayField(TEXT("dispatchers"), Disp))
	{
		const UEdGraphSchema_K2* K2 = GetDefault<UEdGraphSchema_K2>();
		for (const TSharedPtr<FJsonValue>& V : *Disp)
		{
			const FName Name(*V->AsObject()->GetStringField(TEXT("name")));
			FEdGraphPinType DT; DT.PinCategory = UEdGraphSchema_K2::PC_MCDelegate;
			if (!FBlueprintEditorUtils::AddMemberVariable(BP, Name, DT)) { Ctx.Err(FString::Printf(TEXT("dispatcher %s: AddMemberVariable failed"), *Name.ToString())); continue; }
			UEdGraph* G = FBlueprintEditorUtils::CreateNewGraph(BP, Name, UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());
			G->bEditable = false;
			K2->CreateDefaultNodesForGraph(*G);
			K2->CreateFunctionGraphTerminators(*G, (UClass*)nullptr);
			K2->AddExtraFunctionFlags(G, (FUNC_BlueprintCallable | FUNC_BlueprintEvent | FUNC_Public));
			K2->MarkFunctionEntryAsEditable(G, true);
			BP->DelegateSignatureGraphs.Add(G);
		}
	}
	// 3c. Function stubs ("functions": [{"name": "SetLocked", "params": [{"name": "Locked", "type": "bool"}]}]): an empty function graph with
	// the inputs, so that Blueprints calling it still compile. Functions the parent class already has are not stubbed (they stay inherited).
	const TArray<TSharedPtr<FJsonValue>>* Funcs = nullptr;
	if (Spec->TryGetArrayField(TEXT("functions"), Funcs))
	{
		for (const TSharedPtr<FJsonValue>& V : *Funcs)
		{
			const TSharedPtr<FJsonObject> O = V->AsObject();
			const FName Name(*O->GetStringField(TEXT("name")));
			FString Kind; O->TryGetStringField(TEXT("kind"), Kind);
			if (UFunction* PF = Parent->FindFunctionByName(Name))
			{
				// an implementable event of a native class (no native body, e.g. ReceiveTick): an empty override like the game's (whose logic is
				// not in cooked data) keeps what the compiler derives from it (bCanEverTick). Native events and parent Blueprint functions stay inherited.
				UClass* Owner = PF->GetOwnerClass();
				UEdGraph* EG = FBlueprintEditorUtils::FindEventGraph(BP);
				if (Kind == TEXT("Event") && EG && Owner && Owner->HasAnyClassFlags(CLASS_Native) && PF->HasAnyFunctionFlags(FUNC_BlueprintEvent) && !PF->HasAnyFunctionFlags(FUNC_Native))
				{
					UK2Node_Event* EN = NewObject<UK2Node_Event>(EG);
					EN->EventReference.SetExternalMember(Name, Owner);
					EN->bOverrideFunction = true;
					EG->AddNode(EN, false, false);
					EN->CreateNewGuid();
					EN->PostPlacedNewNode();
					EN->AllocateDefaultPins();
				}
				continue;
			}
			const TArray<TSharedPtr<FJsonValue>>* Ps = nullptr;
			O->TryGetArrayField(TEXT("params"), Ps);
			if (Kind == TEXT("Event"))
			{
				UEdGraph* EG = FBlueprintEditorUtils::FindEventGraph(BP);
				if (!EG) { Ctx.Err(FString::Printf(TEXT("event %s: no EventGraph"), *Name.ToString())); continue; }
				UK2Node_CustomEvent* E = NewObject<UK2Node_CustomEvent>(EG);
				E->CustomFunctionName = Name;
				E->bIsEditable = true;
				EG->AddNode(E, false, false);
				E->CreateNewGuid();
				E->PostPlacedNewNode();
				E->AllocateDefaultPins();
				for (const TSharedPtr<FJsonValue>& PV : (Ps ? *Ps : TArray<TSharedPtr<FJsonValue>>()))
				{
					const TSharedPtr<FJsonObject> PO = PV->AsObject();
					FEdGraphPinType PT; FString TypeErr;
					if (!ParsePinType(PO->GetStringField(TEXT("type")), PT, TypeErr)) { Ctx.Err(FString::Printf(TEXT("event %s param %s: %s"), *Name.ToString(), *PO->GetStringField(TEXT("name")), *TypeErr)); continue; }
					E->CreateUserDefinedPin(FName(*PO->GetStringField(TEXT("name"))), PT, EGPD_Output);
				}
				continue;
			}
			UEdGraph* G = FBlueprintEditorUtils::CreateNewGraph(BP, Name, UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());
			FBlueprintEditorUtils::AddFunctionGraph<UClass>(BP, G, true, nullptr);
			UK2Node_FunctionEntry* Entry = nullptr;
			for (UEdGraphNode* N : G->Nodes) if ((Entry = Cast<UK2Node_FunctionEntry>(N)) != nullptr) break;
			if (Entry && Ps)
			{
				for (const TSharedPtr<FJsonValue>& PV : *Ps)
				{
					const TSharedPtr<FJsonObject> PO = PV->AsObject();
					FEdGraphPinType PT; FString TypeErr;
					if (!ParsePinType(PO->GetStringField(TEXT("type")), PT, TypeErr)) { Ctx.Err(FString::Printf(TEXT("function %s param %s: %s"), *Name.ToString(), *PO->GetStringField(TEXT("name")), *TypeErr)); continue; }
					Entry->CreateUserDefinedPin(FName(*PO->GetStringField(TEXT("name"))), PT, EGPD_Output);
				}
			}
		}
	}

	// Skeleton class must know the components/variables before graph nodes reference them.
	FKismetEditorUtilities::CompileBlueprint(BP, EBlueprintCompileOptions::SkipGarbageCollection);

	// 3d. Overrides of components a parent Blueprint defines ("inherited": [{"name": "Box", "props": {...}}]): inheritable component handler
	// templates, created from the parent's template, so only the given values differ.
	const TArray<TSharedPtr<FJsonValue>>* Inh = nullptr;
	if (Spec->TryGetArrayField(TEXT("inherited"), Inh))
	{
		UInheritableComponentHandler* ICH = BP->GetInheritableComponentHandler(true);
		for (const TSharedPtr<FJsonValue>& V : *Inh)
		{
			const TSharedPtr<FJsonObject> O = V->AsObject();
			const FString Name = O->GetStringField(TEXT("name"));
			USCS_Node* PN = FindInheritedNode(BP, Name);
			if (!PN || !ICH) { Ctx.Err(FString::Printf(TEXT("inherited %s: no such component in the parent Blueprints"), *Name)); continue; }
			UActorComponent* T = ICH->CreateOverridenComponentTemplate(FComponentKey(PN));
			if (!T) { Ctx.Err(FString::Printf(TEXT("inherited %s: CreateOverridenComponentTemplate failed"), *Name)); continue; }
			const TSharedPtr<FJsonObject>* P = nullptr;
			if (O->TryGetObjectField(TEXT("props"), P)) ImportProps(T, *P, Ctx, TEXT("inherited ") + Name);
		}
	}

	// 4. Nodes. Pass 0 makes the custom events (and compiles, so that calls to them find their functions on the skeleton class),
	// pass 1 makes everything else. Positions and ids follow the order in the spec.
	TArray<TPair<FString, TSharedPtr<FJsonObject>>> NodeSpecs;
	TArray<TPair<UK2Node_CreateDelegate*, FString>> Delegates;
	if (bHasNodes)
	{
		for (int32 Pass = 0; Pass < 2; ++Pass)
		{
			int32 Index = 0;
			for (const TSharedPtr<FJsonValue>& V : *NodeArr)
			{
				const int32 ThisIndex = Index++;
				const TSharedPtr<FJsonObject> J = V->AsObject();
				const FString Id = J->GetStringField(TEXT("id"));
				const bool bEvent = J->GetStringField(TEXT("op")) == TEXT("custom_event");
				if ((Pass == 0) != bEvent) continue;
				if (Ctx.Nodes.Contains(Id)) { Ctx.Err(FString::Printf(TEXT("duplicate node id %s"), *Id)); continue; }
				UEdGraphNode* N = MakeNode(Ctx, J, Id);
				if (!N) continue;
				const TArray<TSharedPtr<FJsonValue>>* Pos = nullptr;
				if (J->TryGetArrayField(TEXT("pos"), Pos) && Pos->Num() == 2) { N->NodePosX = (int32)(*Pos)[0]->AsNumber(); N->NodePosY = (int32)(*Pos)[1]->AsNumber(); }
				else { N->NodePosX = (ThisIndex % 8) * 320; N->NodePosY = (ThisIndex / 8) * 260; }
				Ctx.Nodes.Add(Id, N);
				NodeSpecs.Add(TPair<FString, TSharedPtr<FJsonObject>>(Id, J));
				if (UK2Node_CreateDelegate* CD = Cast<UK2Node_CreateDelegate>(N))
				{
					FString Fn; J->TryGetStringField(TEXT("function"), Fn);
					Delegates.Add(TPair<UK2Node_CreateDelegate*, FString>(CD, Fn));
				}
			}
			if (Pass == 0) FKismetEditorUtilities::CompileBlueprint(BP, EBlueprintCompileOptions::SkipGarbageCollection);
		}
	}

	const TArray<TSharedPtr<FJsonValue>>* Links = nullptr;
	// 5-pre. Exec bridging: a spec may route exec through a node that turns out to be pure (a const BlueprintCallable function is pure in the
	// editor; headers do not always say). Links into such a node's exec input and out of its "then" are joined past it.
	TArray<TPair<FString, FString>> LinkPairs;
	if (Spec->TryGetArrayField(TEXT("links"), Links))
	{
		for (const TSharedPtr<FJsonValue>& V : *Links)
		{
			const TArray<TSharedPtr<FJsonValue>>& L = V->AsArray();
			if (L.Num() == 2) LinkPairs.Add(TPair<FString, FString>(L[0]->AsString(), L[1]->AsString()));
		}
		auto IsExecName = [](const FString& P) { return P.Equals(TEXT("execute"), ESearchCase::IgnoreCase) || P.Equals(TEXT("exec"), ESearchCase::IgnoreCase) || P.Equals(TEXT("in"), ESearchCase::IgnoreCase); };
		auto PureNode = [&](const FString& NodeId) -> bool
		{
			// pure = no exec pin at all. Checking the names "execute"/"then" misread macro nodes whose exec pins are named
			// otherwise (ForEachLoop: "Exec" / "LoopBody" / "Completed") as pure and dropped the links into them.
			UEdGraphNode** N = Ctx.Nodes.Find(NodeId);
			if (!N) return false;
			for (UEdGraphPin* Pin : (*N)->Pins)
			{
				if (Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec) return false;
			}
			return true;
		};
		TMap<FString, TArray<FString>> PredsOf, SuccsOf;   // pure node id -> exec sources / exec destinations
		TArray<TPair<FString, FString>> Kept;
		for (const auto& LP : LinkPairs)
		{
			FString SId, SPin, DId, DPin;
			if (SplitPinRef(LP.Key, SId, SPin) && SplitPinRef(LP.Value, DId, DPin))
			{
				if (IsExecName(DPin) && PureNode(DId)) { PredsOf.FindOrAdd(DId).Add(LP.Key); Ctx.Notes.Add(DId + " is pure: exec bridged"); continue; }
				if ((SPin.Equals(TEXT("then"), ESearchCase::IgnoreCase) || SPin.Equals(TEXT("out"), ESearchCase::IgnoreCase)) && PureNode(SId)) { SuccsOf.FindOrAdd(SId).Add(LP.Value); continue; }
			}
			Kept.Add(LP);
		}
		for (const auto& PE : PredsOf)
		{
			if (const TArray<FString>* Out = SuccsOf.Find(PE.Key)) for (const FString& Src : PE.Value) for (const FString& Dst : *Out) Kept.Add(TPair<FString, FString>(Src, Dst));
		}
		LinkPairs = Kept;
	}

	// 5. Links: ["src.OutPin", "dst.InPin"] (wildcards resolve as links are made, so defaults come after).
	for (const auto& LP : LinkPairs)
	{
		const FString SrcRef = LP.Key, DstRef = LP.Value;
		FString SId, SPin, DId, DPin;
		if (!SplitPinRef(SrcRef, SId, SPin) || !SplitPinRef(DstRef, DId, DPin)) { Ctx.Err(FString::Printf(TEXT("bad link %s -> %s"), *SrcRef, *DstRef)); continue; }
		UEdGraphNode** SN = Ctx.Nodes.Find(SId);
		UEdGraphNode** DN = Ctx.Nodes.Find(DId);
		if (!SN || !DN) { Ctx.Err(FString::Printf(TEXT("link %s -> %s: unknown node"), *SrcRef, *DstRef)); continue; }
		UEdGraphPin* A = FindPin(*SN, SPin, EGPD_Output);
		UEdGraphPin* B = FindPin(*DN, DPin, EGPD_Input);
		if (!A) { Ctx.Err(FString::Printf(TEXT("link: no output pin %s (pins: %s)"), *SrcRef, *PinList(*SN))); continue; }
		if (!B) { Ctx.Err(FString::Printf(TEXT("link: no input pin %s (pins: %s)"), *DstRef, *PinList(*DN))); continue; }
		const FPinConnectionResponse R = Ctx.Schema->CanCreateConnection(A, B);
		if (!Ctx.Schema->TryCreateConnection(A, B)) Ctx.Err(FString::Printf(TEXT("link %s -> %s refused: %s"), *SrcRef, *DstRef, *R.Message.ToString()));
	}

	// 5b. Delegate nodes: pick the function now that the delegate pin's signature is known.
	for (const auto& D : Delegates)
	{
		if (D.Value.IsEmpty()) { Ctx.Err(TEXT("create_delegate without a function")); continue; }
		D.Key->SetFunction(FName(*D.Value));
		D.Key->HandleAnyChangeWithoutNotifying();
	}

	// 6. Pin defaults.
	for (const auto& P : NodeSpecs)
	{
		const TSharedPtr<FJsonObject>* Pins = nullptr;
		if (!P.Value->TryGetObjectField(TEXT("pins"), Pins)) continue;
		for (const auto& KV : (*Pins)->Values)
		{
			FString V;
			if (!KV.Value->TryGetString(V))
			{
				double D; bool B;
				if (KV.Value->TryGetNumber(D)) V = (D == FMath::FloorToDouble(D) && FMath::Abs(D) < 1e9) ? FString::Printf(TEXT("%lld"), (int64)D) : FString::SanitizeFloat(D);
				else if (KV.Value->TryGetBool(B)) V = B ? TEXT("true") : TEXT("false");
			}
			SetPinDefault(Ctx, Ctx.Nodes[P.Key], P.Key, KV.Key, V);
		}
	}

	// 7. Compile, report, save.
	CompileAndReport(Ctx, Lines);
	// 7a. Class default values ("cdo": {Property: value}): native properties of the parent class and the Blueprint's own variables.
	const TSharedPtr<FJsonObject>* CdoSpec = nullptr;
	if (Spec->TryGetObjectField(TEXT("cdo"), CdoSpec) && BP->GeneratedClass)
	{
		UObject* CDO = BP->GeneratedClass->GetDefaultObject();
		ImportProps(CDO, *CdoSpec, Ctx, TEXT("class defaults"));
		CDO->MarkPackageDirty();
	}
	// 7b. Overrides of components the native parent creates ("nativeOverrides": [{"name": "Audio", "props": {...}}]): their subobjects on the CDO
	const TArray<TSharedPtr<FJsonValue>>* Nat = nullptr;
	if (Spec->TryGetArrayField(TEXT("nativeOverrides"), Nat) && BP->GeneratedClass)
	{
		UObject* CDO = BP->GeneratedClass->GetDefaultObject();
		for (const TSharedPtr<FJsonValue>& V : *Nat)
		{
			const TSharedPtr<FJsonObject> O = V->AsObject();
			const FString Name = O->GetStringField(TEXT("name"));
			UObject* Sub = CDO->GetDefaultSubobjectByName(FName(*Name));
			if (!Sub) { Ctx.Err(FString::Printf(TEXT("native component %s: not on the class default object"), *Name)); continue; }
			const TSharedPtr<FJsonObject>* P = nullptr;
			if (O->TryGetObjectField(TEXT("props"), P) && (*P)->Values.Num()) { Sub->Modify(); ImportProps(Sub, *P, Ctx, TEXT("native component ") + Name); }
		}
		CDO->MarkPackageDirty();
	}
	for (const FString& Note : Ctx.Notes) Lines.Add(TEXT("  note: ") + Note);
	if (USimpleConstructionScript* SCS = BP->SimpleConstructionScript)
	{
		TArray<FString> Roots;
		for (USCS_Node* R : SCS->GetRootNodes())
		{
			TArray<FString> Kids;
			for (USCS_Node* K : R->GetChildNodes()) Kids.Add(K->GetVariableName().ToString());
			Roots.Add(FString::Printf(TEXT("%s[%s]"), *R->GetVariableName().ToString(), *FString::Join(Kids, TEXT(","))));
		}
		Lines.Add(TEXT("  components: ") + FString::Join(Roots, TEXT(" ")));
	}
	if (UBlueprintGeneratedClass* GC = Cast<UBlueprintGeneratedClass>(BP->GeneratedClass))
	{
		for (TFieldIterator<UFunction> It(GC, EFieldIteratorFlags::ExcludeSuper); It; ++It)
		{
			Lines.Add(FString::Printf(TEXT("  function %s: %d bytes of bytecode"), *It->GetName(), It->Script.Num()));
		}
	}
	FAssetRegistryModule::AssetCreated(BP);
	Pkg->MarkPackageDirty();
	const FString File = FPackageName::LongPackageNameToFilename(Asset, FPackageName::GetAssetPackageExtension());
	const bool bSaved = UPackage::SavePackage(Pkg, nullptr, RF_Standalone, *File, GError, nullptr, false, true, SAVE_NoError);
	if (!bSaved) Ctx.Errors.Add(TEXT("save failed: ") + File);

	TArray<FString> Out;
	Out.Add(FString::Printf(TEXT("%s %s (%s, %d nodes, %d errors)"), Ctx.Errors.Num() ? TEXT("ERROR") : TEXT("OK"), *Asset, bNew ? TEXT("created") : TEXT("rebuilt"), Ctx.Nodes.Num(), Ctx.Errors.Num()));
	for (const FString& E : Ctx.Errors) Out.Add(TEXT("  error: ") + E);
	Out.Append(Lines);
	const FString Report = FString::Join(Out, TEXT("\n"));
	UE_LOG(LogItrBPGen, Display, TEXT("%s"), *Report);
	if (Ctx.Errors.Num() == 0) GGenerated.Add(Key, FileTime);
	return Report;
}

// ---- Read-back: what a generated (or any) Blueprint really holds, as JSON. Used by the audit's step 4. ----
// components: SCS nodes (class, parent, socket) with every template property that differs from its class default, as T3D export text;
// cdo: class-default properties that differ from the parent class (or are declared by the Blueprint); variables; graph counts.
FString UItrShowcaseBPGen::DumpBlueprint(const FString& AssetPath)
{
	const FString Name = FPackageName::GetLongPackageAssetName(AssetPath);
	UBlueprint* BP = LoadObject<UBlueprint>(nullptr, *(AssetPath + TEXT(".") + Name), nullptr, LOAD_NoWarn | LOAD_Quiet);
	if (!BP) return FString::Printf(TEXT("{\"error\":\"cannot load %s\"}"), *AssetPath);

	auto Diff = [](UObject* Obj, UObject* Defaults, TSharedRef<FJsonObject> Into, bool bOwnedAlways, UClass* Owner)
	{
		for (TFieldIterator<FProperty> It(Obj->GetClass()); It; ++It)
		{
			FProperty* P = *It;
			if (P->HasAnyPropertyFlags(CPF_Transient | CPF_Deprecated)) continue;
			if (FObjectPropertyBase* OP = CastField<FObjectPropertyBase>(P))
			{
				if (P->HasAnyPropertyFlags(CPF_InstancedReference) && OP->PropertyClass && OP->PropertyClass->IsChildOf(UActorComponent::StaticClass())) continue; // component variables
			}
			const bool bOwned = bOwnedAlways && Owner && P->GetOwnerClass() == Owner;
			if (!bOwned && Defaults && P->Identical_InContainer(Obj, Defaults)) continue;
			FString Text;
			P->ExportText_InContainer(0, Text, Obj, bOwned ? nullptr : Defaults, Obj, PPF_None);
			Into->SetStringField(P->GetName(), Text);
		}
	};

	TSharedRef<FJsonObject> Root = MakeShared<FJsonObject>();
	Root->SetStringField(TEXT("asset"), AssetPath);
	Root->SetStringField(TEXT("parentClass"), BP->ParentClass ? BP->ParentClass->GetPathName() : FString());
	Root->SetStringField(TEXT("status"), BP->Status == BS_UpToDate ? TEXT("UpToDate") : BP->Status == BS_UpToDateWithWarnings ? TEXT("UpToDateWithWarnings") : BP->Status == BS_Error ? TEXT("Error") : TEXT("Dirty/Unknown"));

	TArray<TSharedPtr<FJsonValue>> Comps;
	if (USimpleConstructionScript* SCS = BP->SimpleConstructionScript)
	{
		const TArray<USCS_Node*> Roots = SCS->GetRootNodes();
		TArray<USCS_Node*> AllN = SCS->GetAllNodes();
		if (SCS->GetDefaultSceneRootNode() && !AllN.Contains(SCS->GetDefaultSceneRootNode())) AllN.Add(SCS->GetDefaultSceneRootNode());   // kept but unused
		for (USCS_Node* N : AllN)
		{
			if (!N) continue;
			TSharedRef<FJsonObject> C = MakeShared<FJsonObject>();
			C->SetStringField(TEXT("name"), N->GetVariableName().ToString());
			C->SetStringField(TEXT("class"), N->ComponentClass ? N->ComponentClass->GetPathName() : FString());
			USCS_Node* ParentNode = SCS->FindParentNode(N);
			C->SetStringField(TEXT("parent"), ParentNode ? ParentNode->GetVariableName().ToString() : N->ParentComponentOrVariableName.ToString());
			C->SetBoolField(TEXT("parentNative"), N->bIsParentComponentNative);
			C->SetStringField(TEXT("socket"), N->AttachToName.ToString());
			C->SetBoolField(TEXT("isRoot"), Roots.Contains(N));
			C->SetBoolField(TEXT("unusedDefaultRoot"), N == SCS->GetDefaultSceneRootNode() && !SCS->GetAllNodes().Contains(N));
			C->SetStringField(TEXT("guid"), N->VariableGuid.ToString(EGuidFormats::DigitsWithHyphens));
			TSharedRef<FJsonObject> Props = MakeShared<FJsonObject>();
			if (UActorComponent* T = N->ComponentTemplate) Diff(T, T->GetClass()->GetDefaultObject(), Props, false, nullptr);
			C->SetObjectField(TEXT("props"), Props);
			Comps.Add(MakeShared<FJsonValueObject>(C));
		}
	}
	Root->SetArrayField(TEXT("components"), Comps);

	TArray<TSharedPtr<FJsonValue>> Inh, Orphans;
	if (UInheritableComponentHandler* ICH = BP->GetInheritableComponentHandler(false))
	{
		for (auto It = ICH->CreateRecordIterator(); It; ++It)
		{
			if (!It->ComponentTemplate) continue;
			TSharedRef<FJsonObject> C = MakeShared<FJsonObject>();
			// T-116: a record whose key no longer matches a node of the current parent Blueprints is ignored when the actor is constructed
			// (the parent's template shows through). Reported separately so the comparison fails instead of reading the dead override.
			if (!It->ComponentKey.GetOriginalTemplate())
			{
				C->SetStringField(TEXT("name"), It->ComponentKey.GetSCSVariableName().ToString());
				C->SetStringField(TEXT("guid"), It->ComponentKey.GetAssociatedGuid().ToString(EGuidFormats::DigitsWithHyphens));
				Orphans.Add(MakeShared<FJsonValueObject>(C));
				continue;
			}
			C->SetStringField(TEXT("name"), It->ComponentKey.GetSCSVariableName().ToString());
			C->SetStringField(TEXT("class"), It->ComponentTemplate->GetClass()->GetPathName());
			TSharedRef<FJsonObject> Props = MakeShared<FJsonObject>();
			Diff(It->ComponentTemplate, It->ComponentTemplate->GetArchetype(), Props, false, nullptr);
			C->SetObjectField(TEXT("props"), Props);
			Inh.Add(MakeShared<FJsonValueObject>(C));
		}
	}
	Root->SetArrayField(TEXT("inherited"), Inh);
	Root->SetArrayField(TEXT("orphanedInherited"), Orphans);
	TArray<TSharedPtr<FJsonValue>> Nat;
	if (BP->GeneratedClass && BP->ParentClass)
	{
		UObject* CDO = BP->GeneratedClass->GetDefaultObject();
		UObject* PCDO = BP->ParentClass->GetDefaultObject();
		TArray<UObject*> Subs;
		CDO->GetDefaultSubobjects(Subs);
		for (UObject* S : Subs)
		{
			UActorComponent* AC = Cast<UActorComponent>(S);
			if (!AC) continue;
			UObject* PS = PCDO ? PCDO->GetDefaultSubobjectByName(S->GetFName()) : nullptr;
			TSharedRef<FJsonObject> C = MakeShared<FJsonObject>();
			C->SetStringField(TEXT("name"), S->GetName());
			C->SetStringField(TEXT("class"), S->GetClass()->GetPathName());
			TSharedRef<FJsonObject> Props = MakeShared<FJsonObject>();
			Diff(S, PS ? PS : S->GetClass()->GetDefaultObject(), Props, false, nullptr);
			C->SetObjectField(TEXT("props"), Props);
			Nat.Add(MakeShared<FJsonValueObject>(C));
		}
	}
	Root->SetArrayField(TEXT("nativeOverrides"), Nat);
	TArray<TSharedPtr<FJsonValue>> Fns;
	for (UEdGraph* G : BP->FunctionGraphs) if (G) Fns.Add(MakeShared<FJsonValueString>(G->GetName()));
	for (UEdGraph* G : BP->UbergraphPages) if (G) for (UEdGraphNode* N : G->Nodes) if (UK2Node_CustomEvent* E = Cast<UK2Node_CustomEvent>(N)) Fns.Add(MakeShared<FJsonValueString>(E->CustomFunctionName.ToString()));
	Root->SetArrayField(TEXT("functions"), Fns);
	TArray<TSharedPtr<FJsonValue>> Ds;
	for (UEdGraph* G : BP->DelegateSignatureGraphs) if (G) Ds.Add(MakeShared<FJsonValueString>(G->GetName()));
	Root->SetArrayField(TEXT("dispatchers"), Ds);

	TSharedRef<FJsonObject> Cdo = MakeShared<FJsonObject>();
	if (BP->GeneratedClass && BP->ParentClass) Diff(BP->GeneratedClass->GetDefaultObject(), BP->ParentClass->GetDefaultObject(), Cdo, true, BP->GeneratedClass);
	Root->SetObjectField(TEXT("cdo"), Cdo);

	TArray<TSharedPtr<FJsonValue>> Vars;
	for (const FBPVariableDescription& V : BP->NewVariables)
	{
		TSharedRef<FJsonObject> O = MakeShared<FJsonObject>();
		O->SetStringField(TEXT("name"), V.VarName.ToString());
		O->SetStringField(TEXT("category"), V.VarType.PinCategory.ToString());
		O->SetStringField(TEXT("subCategoryObject"), V.VarType.PinSubCategoryObject.IsValid() ? V.VarType.PinSubCategoryObject->GetPathName() : FString());
		O->SetBoolField(TEXT("array"), V.VarType.ContainerType == EPinContainerType::Array);
		O->SetStringField(TEXT("default"), V.DefaultValue);
		O->SetBoolField(TEXT("instanceEditable"), (V.PropertyFlags & CPF_DisableEditOnInstance) == 0);
		Vars.Add(MakeShared<FJsonValueObject>(O));
	}
	Root->SetArrayField(TEXT("variables"), Vars);

	int32 UberNodes = 0;
	for (UEdGraph* G : BP->UbergraphPages) if (G) UberNodes += G->Nodes.Num();
	Root->SetNumberField(TEXT("eventGraphNodes"), UberNodes);
	Root->SetNumberField(TEXT("functionGraphs"), BP->FunctionGraphs.Num());
	Root->SetNumberField(TEXT("delegateSignatureGraphs"), BP->DelegateSignatureGraphs.Num());

	FString Out;
	TSharedRef<TJsonWriter<>> W = TJsonWriterFactory<>::Create(&Out);
	FJsonSerializer::Serialize(Root, W);
	return Out;
}
