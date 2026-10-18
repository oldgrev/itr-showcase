#pragma once

#include "CoreMinimal.h"
#include "ExplosionParticalInfo.h"
#include "ExplosionInfo.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FExplosionInfo {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float MaxDamage;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float MaxRange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool HasImpulse;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float NoiseDistance;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FExplosionParticalInfo ParticalInfo;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    USoundBase* ExplosionSound;
    UPROPERTY(BlueprintReadWrite)
    bool IsForceTrace;
    FExplosionInfo();
};
