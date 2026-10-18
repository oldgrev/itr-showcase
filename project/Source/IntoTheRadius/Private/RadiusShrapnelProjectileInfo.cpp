#include "RadiusShrapnelProjectileInfo.h"

URadiusShrapnelProjectileInfo::URadiusShrapnelProjectileInfo(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

URadiusShrapnelProjectileInfo* URadiusShrapnelProjectileInfo::CreateInfo(const FAmmoInfo& AmmoInfo, float BaseDamage, float AccuracyInternal, float AccuracyMultiplier, float Offset, float TraceDistance) {
    return {};
}

