#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "AccuracyParameters.h"
#include "AmmoContainerParameters.h"
#include "EItemSlot.h"
#include "EWeaponInfoParameter.h"
#include "ItemParameters.h"
#include "ItemShopInfo.h"
#include "RecoilParameters.h"
#include "WeaponParameters.h"
#include "UpgradeInfo.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FUpgradeInfo : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag UpgradeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<FGameplayTag> ConflictUpgradeIDs;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<FGameplayTag> RequiredUpgradeIDs;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UTexture2D* Icon;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FText Description;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 InstallPrice;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool ShowInInfo;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TMap<EWeaponInfoParameter, int32> InfoParametersChange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FItemShopInfo ItemPricesChange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FItemParameters ItemParametersChange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FAccuracyParameters AccuracyParametersChange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FRecoilParameters RecoilParametersChange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FWeaponParameters WeaponParametersChange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FAmmoContainerParameters AmmoContainerParametersChange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TMap<EItemSlot, FGameplayTag> AttachmentSlotsChange;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool bUseCamoSkin;
    FUpgradeInfo();
    ~FUpgradeInfo();
};
