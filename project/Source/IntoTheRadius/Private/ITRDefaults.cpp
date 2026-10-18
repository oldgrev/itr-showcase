#include "ITRDefaults.h"

#include "UObject/Class.h"
#include "UObject/SoftObjectPtr.h"
#include "UObject/UnrealType.h"
#include "UObject/UObjectGlobals.h"

namespace
{
	// Resolve "A.B[2].C" to (leaf property, value address). Arrays grow to fit the index.
	FProperty* Resolve(UStruct* Type, void* Container, const TCHAR* Path, void*& OutAddr)
	{
		if (!UObjectInitialized() || !Type || !Container)
			return nullptr;
		TArray<FString> Tokens;
		FString(Path).ParseIntoArray(Tokens, TEXT("."));
		UStruct* Struct = Type;
		void* Base = Container;
		FProperty* Prop = nullptr;
		void* Addr = nullptr;
		for (int32 t = 0; t < Tokens.Num(); ++t)
		{
			FString Name = Tokens[t];
			int32 Index = INDEX_NONE;
			int32 Bracket;
			if (Name.FindChar('[', Bracket))
			{
				Index = FCString::Atoi(*Name.Mid(Bracket + 1));
				Name = Name.Left(Bracket);
			}
			if (!Struct)
				return nullptr;
			Prop = FindFProperty<FProperty>(Struct, *Name);
			if (!Prop)
				return nullptr;
			if (Index != INDEX_NONE && Prop->ArrayDim > 1)
			{
				if (Index >= Prop->ArrayDim)
					return nullptr;
				Addr = Prop->ContainerPtrToValuePtr<void>(Base, Index);
			}
			else
			{
				Addr = Prop->ContainerPtrToValuePtr<void>(Base);
				if (Index != INDEX_NONE)
				{
					FArrayProperty* Arr = CastField<FArrayProperty>(Prop);
					if (!Arr)
						return nullptr;
					FScriptArrayHelper H(Arr, Addr);
					if (H.Num() <= Index)
						H.AddValues(Index + 1 - H.Num());
					Addr = H.GetRawPtr(Index);
					Prop = Arr->Inner;
				}
			}
			if (t + 1 < Tokens.Num())
			{
				FStructProperty* SP = CastField<FStructProperty>(Prop);
				if (!SP)
					return nullptr;
				Struct = SP->Struct;
				Base = Addr;
				// next token resolves inside the struct: ContainerPtrToValuePtr on Base with the member offset
			}
		}
		OutAddr = Addr;
		return Prop;
	}
}

namespace ITRDefaults
{
	void Set(UStruct* Type, void* Container, const TCHAR* Path, bool Value)
	{
		void* Addr;
		if (FBoolProperty* P = CastField<FBoolProperty>(Resolve(Type, Container, Path, Addr)))
			P->SetPropertyValue(Addr, Value);
	}

	void Set(UStruct* Type, void* Container, const TCHAR* Path, double Value)
	{
		void* Addr;
		FProperty* P = Resolve(Type, Container, Path, Addr);
		if (FEnumProperty* E = CastField<FEnumProperty>(P))
			E->GetUnderlyingProperty()->SetIntPropertyValue(Addr, (int64)Value);
		else if (FNumericProperty* N = CastField<FNumericProperty>(P))
		{
			if (N->IsFloatingPoint())
				N->SetFloatingPointPropertyValue(Addr, Value);
			else
				N->SetIntPropertyValue(Addr, (int64)Value);
		}
		else if (FBoolProperty* B = CastField<FBoolProperty>(P))
			B->SetPropertyValue(Addr, Value != 0.0);
	}

	void Set(UStruct* Type, void* Container, const TCHAR* Path, const TCHAR* Value)
	{
		void* Addr;
		FProperty* P = Resolve(Type, Container, Path, Addr);
		if (FNameProperty* N = CastField<FNameProperty>(P))
			N->SetPropertyValue(Addr, FName(Value));
		else if (FStrProperty* S = CastField<FStrProperty>(P))
			S->SetPropertyValue(Addr, FString(Value));
		else if (FSoftObjectProperty* SO = CastField<FSoftObjectProperty>(P))
			*(FSoftObjectPtr*)Addr = FSoftObjectPath(Value);
		else if (FObjectPropertyBase* O = CastField<FObjectPropertyBase>(P))
			O->SetObjectPropertyValue(Addr, Native(Value));
	}

	void SetObject(UStruct* Type, void* Container, const TCHAR* Path, UObject* Value)
	{
		void* Addr;
		if (FObjectPropertyBase* O = CastField<FObjectPropertyBase>(Resolve(Type, Container, Path, Addr)))
			O->SetObjectPropertyValue(Addr, Value);
	}

	void SetNum(UStruct* Type, void* Container, const TCHAR* ArrayPath, int32 Num)
	{
		void* Addr;
		if (FArrayProperty* A = CastField<FArrayProperty>(Resolve(Type, Container, ArrayPath, Addr)))
		{
			FScriptArrayHelper H(A, Addr);
			H.Resize(Num);
		}
	}

	UObject* Native(const TCHAR* ScriptPath)
	{
		return StaticFindObject(UObject::StaticClass(), nullptr, ScriptPath);
	}
}
