#include "GameInventory.h"

UGameInventory::UGameInventory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UGameInventory::SetAmmoBeltContent(const FString& InstanceId, TArray<FGameplayTag> beltContent) {
}

UInventoryItem* UGameInventory::GetItem(const FString& InstanceId) {
    return {};
}

void UGameInventory::GetAmmoBeltContent(const FString& InstanceId, TArray<FGameplayTag>& beltContent) {
}

