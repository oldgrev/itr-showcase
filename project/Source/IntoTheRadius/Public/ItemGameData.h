#pragma once

#include "CoreMinimal.h"
#include "ItemGameData.generated.h"

class UInventoryItem;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FItemGameData {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    UInventoryItem* Item;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform Transform;
    FItemGameData();
};
