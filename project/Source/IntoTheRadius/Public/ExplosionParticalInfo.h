#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ExplosionParticalInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FExplosionParticalInfo {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag Tag;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 Count;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float Velocity;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float BaseDamage;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float MaxDistance;
    UPROPERTY(BlueprintReadWrite)
    bool IsInAir;
    FExplosionParticalInfo();
};
