#include "RadiusImpactInfo.h"

#include "ITRDefaults.h"
FRadiusImpactInfo::FRadiusImpactInfo() {
    Template = {};
    SoundCue = {};
    SoundDistance = {};
    SoundVolumnMultiplier = {};
    SoundDelay = {};
    DecalMaterial = {};
    AttachToComponent = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReflectionVector.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReflectionVector.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReflectionVector.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DecalScale.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DecalScale.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DecalScale.Z"), (double)0);
}
