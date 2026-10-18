#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AmmoContainerParameters.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FAmmoContainerParameters {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<FGameplayTag> AcceptedAmmoTypes;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 ChamberCapacity;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 HolderCapacity;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DurabilityDamagePerAmmo;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float CapacityDurabilityCoefficient;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DamageToReliabilityDebonus;
    FAmmoContainerParameters();
    ~FAmmoContainerParameters();
};
