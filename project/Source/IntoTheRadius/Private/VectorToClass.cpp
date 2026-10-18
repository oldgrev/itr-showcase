#include "VectorToClass.h"

#include "ITRDefaults.h"
FVectorToClass::FVectorToClass() {
    Class = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Vector.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Vector.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Vector.Z"), (double)0);
}
