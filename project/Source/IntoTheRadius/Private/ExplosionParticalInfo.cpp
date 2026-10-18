#include "ExplosionParticalInfo.h"

#include "ITRDefaults.h"
FExplosionParticalInfo::FExplosionParticalInfo() {
    Count = {};
    Velocity = {};
    BaseDamage = {};
    MaxDistance = {};
    IsInAir = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Tag.TagName"), TEXT("None"));
}
