#include "ItemStashPoint.h"
#include "ITRDefaults.h"

UItemStashPoint::UItemStashPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::SetNum(GetClass(), this, TEXT("GameplayTags.GameplayTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("GameplayTags.ParentTags"), 0);
}

void UItemStashPoint::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const {
}

