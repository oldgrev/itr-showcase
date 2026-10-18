#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "AccuracyParameters.h"
#include "EItemSlot.h"
#include "RecoilParameters.h"
#include "WeaponParameters.h"
#include "WeaponInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FWeaponInfo : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag ItemTypeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool UseVirtualStock;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FAccuracyParameters AccuracyParameters;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FRecoilParameters RecoilParameters;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FWeaponParameters WeaponParameters;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<FGameplayTag> PossibleUpgrades;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TMap<EItemSlot, FGameplayTag> AttachmentSlots;
    FWeaponInfo();
    ~FWeaponInfo();
};
