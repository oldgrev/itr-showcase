#include "RadiusEmitterInfo.h"

#include "ITRDefaults.h"
FRadiusEmitterInfo::FRadiusEmitterInfo() {
    Template = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReflectionVector.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReflectionVector.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReflectionVector.Z"), (double)0);
}

FRadiusEmitterInfo::~FRadiusEmitterInfo() {
}
