#pragma once

#include "CoreMinimal.h"
#include "BaseItemSpawnInfo.h"
#include "RadiusItemActor.h"
#include "RadiusBaseItem.generated.h"

class UInventoryItem;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusBaseItem : public ARadiusItemActor {
    GENERATED_BODY()
public:
    ARadiusBaseItem(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintImplementableEvent)
    void Setup(const FBaseItemSpawnInfo& BaseItemSpawnInfo);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void ResetInventoryItemRef();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    bool IsInitInventoryItem();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UInventoryItem* InitInventoryItem();

};
