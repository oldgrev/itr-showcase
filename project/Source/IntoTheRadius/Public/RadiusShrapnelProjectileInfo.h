#pragma once

#include "CoreMinimal.h"
#include "AmmoInfo.h"
#include "RadiusFirearmProjectileInfo.h"
#include "RadiusShrapnelProjectileInfo.generated.h"

class URadiusShrapnelProjectileInfo;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API URadiusShrapnelProjectileInfo : public URadiusFirearmProjectileInfo {
    GENERATED_BODY()
public:
    URadiusShrapnelProjectileInfo(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static URadiusShrapnelProjectileInfo* CreateInfo(const FAmmoInfo& AmmoInfo, float BaseDamage, float AccuracyInternal, float AccuracyMultiplier, float Offset, float TraceDistance);

};
