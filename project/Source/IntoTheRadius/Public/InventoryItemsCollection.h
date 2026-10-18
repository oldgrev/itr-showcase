#pragma once

#include "CoreMinimal.h"
#include "IClearable.h"
#include "InventoryItemsCollection.generated.h"

class UInventoryItem;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UInventoryItemsCollection : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UInventoryItemsCollection(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadOnly)
    TArray<UInventoryItem*> Items;
};
