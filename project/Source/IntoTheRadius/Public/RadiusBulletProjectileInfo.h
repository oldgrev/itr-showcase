#pragma once

#include "CoreMinimal.h"
#include "AmmoInfo.h"
#include "RadiusFirearmProjectileInfo.h"
#include "RadiusBulletProjectileInfo.generated.h"

class URadiusBulletProjectileInfo;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API URadiusBulletProjectileInfo : public URadiusFirearmProjectileInfo {
    GENERATED_BODY()
public:
    URadiusBulletProjectileInfo(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static URadiusBulletProjectileInfo* CreateInfo(const FAmmoInfo& AmmoInfo, const float Velocity, const float BaseDamage, const bool ForceTracer);

};
