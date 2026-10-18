#include "InventoryManager.h"

UInventoryManager::UInventoryManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UInventoryManager::TakeActor(AActor* Actor, const FGameplayTag HolderID, bool& bSuccess, UInventoryItem*& InventoryItem) {
}

void UInventoryManager::SellItems(TArray<AActor*> Items, float PriceMultiplier) {
}

void UInventoryManager::RepairItems(TArray<UInventoryItem*> Items, bool& bSuccess) {
}

void UInventoryManager::RemovePlayerItems(bool bDestroyActors) {
}

void UInventoryManager::RemoveItemByRef(AActor* Actor, bool& success) {
}

bool UInventoryManager::RemoveItem(UInventoryItem* Item) {
    return {};
}

void UInventoryManager::RecordUniqueItemSpawn(const FString& InstanceId, bool& success) {
}

void UInventoryManager::RecordStashOpen(FGameplayTag stashType, const FString& stashID, bool& success) {
}

void UInventoryManager::OnSecondsAddedToTime(float Seconds) {
}

void UInventoryManager::KillPlayerItems() {
}

void UInventoryManager::KillAllInventoryItems(bool fullClear) {
}

void UInventoryManager::IsUniqueItemSpawned(const FString& InstanceId, bool& spawned) {
}

void UInventoryManager::IsStashOpened(FGameplayTag stashType, const FString& stashID, bool& opened) {
}

bool UInventoryManager::IsNeedRepair(UInventoryItem* Item) {
    return {};
}

bool UInventoryManager::IsInPlayerInventory(UInventoryItem* Item) {
    return {};
}

bool UInventoryManager::IsInLevelsInventory(UInventoryItem* Item) {
    return {};
}

bool UInventoryManager::IsInHubInventory(UInventoryItem* Item) {
    return {};
}

bool UInventoryManager::IsActorInPlayerInventory(AActor* itemActor) {
    return {};
}

void UInventoryManager::GetSilencerAttachment(UInventoryItem* parentItem, UInventoryItem*& AttachItem) {
}

void UInventoryManager::GetRepairStatus(bool& bEmpty, bool& bReady, TArray<UInventoryItem*>& RepairItems) {
}

void UInventoryManager::GetPlayerItems(TArray<UInventoryItem*>& inventoryItems) {
}

UInventoryItemsCollection* UInventoryManager::GetPlayerInventoryCollection() const {
    return {};
}

void UInventoryManager::GetMagAttachment(UInventoryItem* parentItem, UInventoryItem*& AttachItem) {
}

void UInventoryManager::GetLevelsItems(TMap<FGameplayTag, UInventoryItemsCollection*>& levelsItems) {
}

FGameplayTag UInventoryManager::GetItemLevel(UInventoryItem* Item) {
    return {};
}

void UInventoryManager::GetItemBP(const FString& InstanceId, UInventoryItem*& InventoryItem) {
}

void UInventoryManager::GetInventoryWeight(const FGameplayTag inHolderID, float& TotalWeight) {
}

UInventoryManager* UInventoryManager::GetInventoryManager() {
    return {};
}

void UInventoryManager::GetCurrentLevelItems(TArray<UInventoryItem*>& inventoryItems) {
}

void UInventoryManager::GetAttachments(UInventoryItem* parentItem, const FGameplayTag TypeTag, TArray<UInventoryItem*>& AttachItems) {
}

void UInventoryManager::GetAttachedToSlot(UInventoryItem* parentItem, const EItemSlot Slot, UInventoryItem*& AttachItem) {
}

void UInventoryManager::GetAllAttachments(UInventoryItem* parentItem, TArray<UInventoryItem*>& AttachItems) {
}

void UInventoryManager::FindItemsByTagInPlayer(FGameplayTag Tag, bool strict, bool& success, TArray<UInventoryItem*>& inventoryItems) {
}

void UInventoryManager::FindItemsByTagInLevel(FGameplayTag Level, FGameplayTag Tag, bool strict, bool& success, TArray<UInventoryItem*>& inventoryItems) {
}

void UInventoryManager::FindItemsByTag(FGameplayTag Tag, bool strict, bool& success, TArray<UInventoryItem*>& inventoryItems) {
}

void UInventoryManager::FindItemsByHolderID(FGameplayTag HolderID, bool& success, TArray<UInventoryItem*>& inventoryItems) {
}

void UInventoryManager::FindItemByRefInPlayer(AActor* Actor, bool& success, UInventoryItem*& InventoryItem) {
}

void UInventoryManager::FindItemByRef(AActor* Actor, bool& success, UInventoryItem*& InventoryItem) {
}

void UInventoryManager::DropPlayerInventory(const bool bKillActors, const bool bDropOnGround, const FGameplayTag FromHolderID, const FVector LocationOffset) {
}

void UInventoryManager::DropItemActor(AActor* Actor, bool bForceBackpackDrop, bool& bSuccess, UInventoryItem*& InventoryItem) {
}

void UInventoryManager::DetachItems(UInventoryItem* itemParent, UInventoryItem* itemAttach, bool& success) {
}

void UInventoryManager::DetachItemActors(AActor* Parent, AActor* attach, bool& success) {
}

void UInventoryManager::ClearAllItemReferences() {
}

void UInventoryManager::CheckPlayerItem(FGameplayTag ItemType, bool strictItemType, FGameplayTag HolderID, bool strictHolderID, bool& success) {
}

bool UInventoryManager::CheckItem(const FString& itemInstanceID, bool pick, FGameplayTag HolderID, bool strictHolderID) {
    return {};
}

void UInventoryManager::CheckAttachments() {
}

void UInventoryManager::BreakActorLink(AActor* Actor) {
}

void UInventoryManager::AttachItems(UInventoryItem* itemParent, UInventoryItem* itemAttach, EItemSlot attachSlot, bool& success) {
}

void UInventoryManager::AttachItemActors(AActor* Parent, AActor* attach, EItemSlot attachToSlot, bool& success) {
}

void UInventoryManager::AddItemToPlayer(UInventoryItem* Item, bool& success) {
}

void UInventoryManager::AddItemToLevel(UInventoryItem* Item, bool noAttachmentsCheck, bool& success) {
}

void UInventoryManager::AddDefaultItemToLevel(FGameplayTag ItemTag, FTransform Transform, bool noAttachmentsCheck, bool& success) {
}

UInventoryItem* UInventoryManager::AddConfigItemToLevel(UPRItemConfig* itemConfig, FTransform Transform, bool noAttachmentsCheck, bool& success) {
    return {};
}

