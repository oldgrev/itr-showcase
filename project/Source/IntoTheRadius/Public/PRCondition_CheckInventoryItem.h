#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRCondition_Item.h"
#include "PRCondition_CheckInventoryItem.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_CheckInventoryItem : public UPRCondition_Item {
    GENERATED_BODY()
public:
    UPRCondition_CheckInventoryItem(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool InPlayerInventory;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> InLevelInventories;
};
