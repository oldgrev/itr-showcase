#include "EventsManager.h"

UEventsManager::UEventsManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

UEventsManager* UEventsManager::GetEventsManager() {
    return {};
}

void UEventsManager::FireOnWildSpawnerCleared(AActor* SpawnerActor) {
}

void UEventsManager::FireOnVirtualStockChanged() {
}

void UEventsManager::FireOnTutorialStarted(FGameplayTag TutorialId) {
}

void UEventsManager::FireOnTutorialSequenceFinished(AActor* SequenceActor) {
}

void UEventsManager::FireOnTriggerUnset(FGameplayTag Trigger) {
}

void UEventsManager::FireOnTriggerPassed(FGameplayTag Trigger) {
}

void UEventsManager::FireOnTransitionStart() {
}

void UEventsManager::FireOnTransitionEnd() {
}

void UEventsManager::FireOnTideHappening() {
}

void UEventsManager::FireOnSwitchAiCoverDebug() {
}

void UEventsManager::FireOnStoryNotePassed(FGameplayTag NoteID) {
}

void UEventsManager::FireOnStashOpened(AActor* StashActor) {
}

void UEventsManager::FireOnShowBodyChanged() {
}

void UEventsManager::FireOnShotFired() {
}

void UEventsManager::FireOnReferencesClearing() {
}

void UEventsManager::FireOnPlayerWalking() {
}

void UEventsManager::FireOnPlayerTurning() {
}

void UEventsManager::FireOnPlayerStarted() {
}

void UEventsManager::FireOnPlayerSleep(const float Seconds, const bool bIsBlackout) {
}

void UEventsManager::FireOnPlayerRunning() {
}

void UEventsManager::FireOnPlayerReset() {
}

void UEventsManager::FireOnPlayerMoneyChanged(const int32 Value, const TArray<FString>& AnalyticsParams) {
}

void UEventsManager::FireOnPlayerLevelChanged(const int32 PlayerLevel) {
}

void UEventsManager::FireOnPlayerKilledNPC(AActor* NPCActor, FGameplayTag weaponTag) {
}

void UEventsManager::FireOnPlayerEyesOpen(bool bIsOpen) {
}

void UEventsManager::FireOnPlayerDied() {
}

void UEventsManager::FireOnPlayerBodyVisibilityChanged(const bool bValue) {
}

void UEventsManager::FireOnPictureTaken(AActor* Actor) {
}

void UEventsManager::FireOnObjectiveRestored(UMissionData* MissionData, UMissionAbstractObjectiveData* objectiveData) {
}

void UEventsManager::FireOnObjectiveProgress(UMissionData* MissionData, UMissionAbstractObjectiveData* objectiveData) {
}

void UEventsManager::FireOnObjectiveFinished(UMissionData* MissionData, UMissionAbstractObjectiveData* objectiveData) {
}

void UEventsManager::FireOnNPCDied(AActor* NPCActor) {
}

void UEventsManager::FireOnNewMissionAdded(UMissionData* MissionData) {
}

void UEventsManager::FireOnNewJournalNote(FGameplayTag NoteID) {
}

void UEventsManager::FireOnMissionStateChanged(UMissionData* MissionData) {
}

void UEventsManager::FireOnMissionPreview(UMissionData* MissionData) {
}

void UEventsManager::FireOnMissionFinished(UMissionData* MissionData) {
}

void UEventsManager::FireOnLevelStarted(FGameplayTag LevelTag) {
}

void UEventsManager::FireOnLevelPrepare(FGameplayTag LevelTag) {
}

void UEventsManager::FireOnLanguageChanged() {
}

void UEventsManager::FireOnItemUpdated(const FGameplayTag ItemTag, const FGameplayTag UpgradeID) {
}

void UEventsManager::FireOnItemTaken(UInventoryItem* InventoryItem) {
}

void UEventsManager::FireOnItemStored(UInventoryItem* InventoryItem) {
}

void UEventsManager::FireOnItemsSold(TArray<UInventoryItem*> Items) {
}

void UEventsManager::FireOnItemRemoved(UInventoryItem* InventoryItem) {
}

void UEventsManager::FireOnItemDropped(AActor* itemActor) {
}

void UEventsManager::FireOnItemChangeDurability(UInventoryItem* InventoryItem) {
}

void UEventsManager::FireOnItemBought(UInventoryItem* InventoryItem) {
}

void UEventsManager::FireOnItemActorRefRemoved(UInventoryItem* InventoryItem) {
}

void UEventsManager::FireOnInventoryModeChanged() {
}

void UEventsManager::FireOnHolderFixed(const FGameplayTag HolderID, const int32 TotalItems, const TArray<FString>& FixedItems) {
}

void UEventsManager::FireOnGameTimeChanged(float DeltaSeconds) {
}

void UEventsManager::FireOnGameStarted() {
}

void UEventsManager::FireOnGameShutdown() {
}

void UEventsManager::FireOnGameplayTimeDilationChanged(float TimeDilation) {
}

void UEventsManager::FireOnGamePaused(const bool bIsPaused) {
}

void UEventsManager::FireOnGameModeStarted() {
}

void UEventsManager::FireOnGameInstanceStarted() {
}

void UEventsManager::FireOnGameDataSaved(const int32 SlotNr, const int32 SaveNr, const float SizeMb) {
}

void UEventsManager::FireOnGameDataSave() {
}

void UEventsManager::FireOnFirstTimeTaken(const FGameplayTag ItemTag) {
}

void UEventsManager::FireOnEnvironmentRePrepared(const APREnvironment* Environment) {
}

void UEventsManager::FireOnDifficultyChanged() {
}

void UEventsManager::FireOnCustomMapMarkPassed(FGameplayTag MarkID) {
}

void UEventsManager::FireOnConsumableUsing(UInventoryItem* Item) {
}

void UEventsManager::FireOnConsumableActorUsing(AActor* itemActor) {
}

