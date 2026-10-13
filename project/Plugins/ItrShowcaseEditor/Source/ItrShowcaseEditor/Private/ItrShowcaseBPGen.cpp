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
	void Err(const FString& S) { Errors.Add(S); UE_LOG(LogItrBPGen, Error, TEXT("%s"), *S); }
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

// bool|byte|int|float|name|string|text|vector|rotator|transform|linearcolor|color|struct:<S>|object:<C>|class:<C>, "[]" suffix = array
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
	else if (Kind == TEXT("object") || Kind == TEXT("class"))
	{
		Out.PinCategory = Kind == TEXT("object") ? UEdGraphSchema_K2::PC_Object : UEdGraphSchema_K2::PC_Class;
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

static bool ImportProps(UObject* Obj, const TSharedPtr<FJsonObject>& Props, FCtx& Ctx, const FString& Where)
{
	if (!Props.IsValid()) return true;
	bool bOk = true;
	for (const auto& KV : Props->Values)
	{
		FProperty* Prop = Obj->GetClass()->FindPropertyByName(FName(*KV.Key));
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
	const FString Asset = Spec->GetStringField(TEXT("asset")); // /Game/Mods/X/BP_Name
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
	if (Spec->TryGetArrayField(TEXT("components"), Comps))
	{
		USimpleConstructionScript* SCS = BP->SimpleConstructionScript;
		TMap<FString, USCS_Node*> ByName;
		// A spec with its own parentless scene component replaces DefaultSceneRoot (otherwise both stay root nodes).
		for (const TSharedPtr<FJsonValue>& V : *Comps)
		{
			UClass* CC = FindClass(V->AsObject()->GetStringField(TEXT("class")));
			if (CC && CC->IsChildOf(USceneComponent::StaticClass()) && !V->AsObject()->HasField(TEXT("attach")) && SCS->GetDefaultSceneRootNode())
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
			USCS_Node* Node = SCS->CreateNode(CC, FName(*Name));
			FString ParentComp;
			if (C->TryGetStringField(TEXT("attach"), ParentComp) && ByName.Contains(ParentComp)) ByName[ParentComp]->AddChildNode(Node);
			else SCS->AddNode(Node);
			ByName.Add(Name, Node);
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

	// Skeleton class must know the components/variables before graph nodes reference them.
	FKismetEditorUtilities::CompileBlueprint(BP, EBlueprintCompileOptions::SkipGarbageCollection);

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
