#include "RadiusBulletProjectileInfo.h"

URadiusBulletProjectileInfo::URadiusBulletProjectileInfo(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

URadiusBulletProjectileInfo* URadiusBulletProjectileInfo::CreateInfo(const FAmmoInfo& AmmoInfo, const float Velocity, const float BaseDamage, const bool ForceTracer) {
    return {};
}

