#pragma once

#include "CoreMinimal.h"
#include "ItemShopInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FItemShopInfo {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SellPriceOverride;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BuyPrice;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform ItemTransformInSlot;
    UPROPERTY(BlueprintReadOnly)
    float RepairPricePerPercent;
    UPROPERTY(BlueprintReadOnly)
    float RepairSecondsPerPercent;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 RequiredPlayerLevel;
    FItemShopInfo();
};
