#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AmmoContainerData.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FAmmoContainerData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTag> Ammo;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag ChamberAmmo;
    FAmmoContainerData();
    ~FAmmoContainerData();
};
