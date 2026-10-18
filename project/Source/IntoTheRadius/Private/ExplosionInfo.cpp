#include "ExplosionInfo.h"

#include "ITRDefaults.h"
FExplosionInfo::FExplosionInfo() {
    MaxDamage = {};
    MaxRange = {};
    HasImpulse = {};
    NoiseDistance = {};
    ExplosionSound = {};
    IsForceTrace = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("MaxDamage"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MaxRange"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("NoiseDistance"), (double)1000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ParticalInfo.Tag.TagName"), TEXT("None"));
}
