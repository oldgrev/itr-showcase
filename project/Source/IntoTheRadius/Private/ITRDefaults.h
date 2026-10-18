// Generated module support (tools/itr-showcase/cppmod, T-117). Applies the game's native constructor defaults, taken
// from the game's CDOs / struct constructors, through reflection: property paths ("A.B[2].C") resolve at runtime, so
// inherited engine properties (private in C++) and nested struct fields need no C++ access.
#pragma once

#include "CoreMinimal.h"

class UObject;
class UStruct;

namespace ITRDefaults
{
	void Set(UStruct* Type, void* Container, const TCHAR* Path, bool Value);
	void Set(UStruct* Type, void* Container, const TCHAR* Path, double Value);
	void Set(UStruct* Type, void* Container, const TCHAR* Path, const TCHAR* Value); // FName / FString / soft path / native object path
	void SetObject(UStruct* Type, void* Container, const TCHAR* Path, UObject* Value);
	void SetNum(UStruct* Type, void* Container, const TCHAR* ArrayPath, int32 Num);

	UObject* Native(const TCHAR* ScriptPath); // FindObject of a /Script object (native class, CDO)
}
