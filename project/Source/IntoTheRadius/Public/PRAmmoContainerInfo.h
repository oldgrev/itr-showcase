#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "AmmoContainerParameters.h"
#include "PRAmmoContainerInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FPRAmmoContainerInfo : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag ItemTypeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool IgnoreChamberCountInInspect;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FAmmoContainerParameters Parameters;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<FGameplayTag> PossibleUpgrades;
    FPRAmmoContainerInfo();
    ~FPRAmmoContainerInfo();
};
