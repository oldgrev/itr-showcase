#include "ItemsManager.h"

UItemsManager::UItemsManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UItemsManager::SetConditionsIgnore(bool ignoreCorpse, bool ignoreStash) {
}

void UItemsManager::PackItems(USceneComponent* Parent, TArray<UInventoryItem*> Items, TArray<UInventoryItem*>& Excluded, const bool bExcludeNonFit, const bool bProjectDown) {
}

void UItemsManager::MultiPackItems(TArray<USceneComponent*> Bounds, TArray<UInventoryItem*> Items, const bool bProjectDown) {
}

void UItemsManager::GetLootForTable(FGameplayTag lootTableTag, int32 LootPoints, const FString& idOverride, TArray<UInventoryItem*>& Items, bool& success) {
}

UItemsManager* UItemsManager::GetItemsManager() {
    return {};
}

void UItemsManager::GetDefaultLoot(TArray<FGameplayTag> itemTags, const FString& idOverride, TArray<UInventoryItem*>& Items) {
}

void UItemsManager::GetCurrentLevelLoot(const int32 LootPoints, const FString& idOverride, TArray<UInventoryItem*>& Items) {
}

void UItemsManager::GetConfiguredLoot(TArray<UPRItemConfig*> ItemConfigs, const FString& idOverride, TArray<UInventoryItem*>& Items) {
}

