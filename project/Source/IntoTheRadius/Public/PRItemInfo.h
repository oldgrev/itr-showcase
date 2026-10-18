#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ArmorParameters.h"
#include "EItemSlot.h"
#include "ItemParameters.h"
#include "ItemShopInfo.h"
#include "PRItemInfo.generated.h"

class AActor;
class UObject;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FPRItemInfo : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag ItemTypeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag AttachmentTypeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TSubclassOf<AActor> ActorClass;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TSubclassOf<UObject> ProxyClass;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FText ItemName;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FText ItemDescription;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FText ItemHelp;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool DestroyedAtZeroDurability;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool ChangeWeightFromDurability;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FItemShopInfo Prices;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FItemParameters ItemParameters;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FArmorParameters ArmorParameters;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<FGameplayTag> PossibleUpgrades;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TMap<EItemSlot, FGameplayTag> AttachmentSlots;
    FPRItemInfo();
    ~FPRItemInfo();
};
