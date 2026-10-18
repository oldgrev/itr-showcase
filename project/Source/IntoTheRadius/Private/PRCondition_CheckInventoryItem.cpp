#include "PRCondition_CheckInventoryItem.h"
#include "ITRDefaults.h"

UPRCondition_CheckInventoryItem::UPRCondition_CheckInventoryItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("InPlayerInventory"), true);
}

