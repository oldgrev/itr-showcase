#include "PRCondition_Item.h"
#include "ITRDefaults.h"

UPRCondition_Item::UPRCondition_Item(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("ItemConfigID.TagName"), TEXT("None"));
}

