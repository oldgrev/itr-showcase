#include "PRGameData.h"
#include "ITRDefaults.h"

UPRGameData::UPRGameData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("UID"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("LastTideTicks"), (double)-1);
    ITRDefaults::Set(GetClass(), this, TEXT("Difficulty"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficulty.EnemySense"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficulty.ItemsDropType"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.Hunger"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.EnemySense"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.EnemyHealth"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.EnemyDamage"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.EnemyCount"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.ItemsDropType"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.ItemSellPrice"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.WeaponShotDamage"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.AnomalyDamage"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.AnomalyAmount"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.MissionMoneyReward"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("GameDifficultyConfig.TideTime"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("IntactDifficulty"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("GameUID"), TEXT("-none-"));
    ITRDefaults::Set(GetClass(), this, TEXT("GameStartDateString"), TEXT("-unknown-"));
    ITRDefaults::Set(GetClass(), this, TEXT("PreviousLevelTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("CurrentLevelTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("NextLevelTag.TagName"), TEXT("None"));
}

void UPRGameData::UpdateMarker(const FString Marker, const bool bRemove) {
}

bool UPRGameData::UnsetTrigger(const FGameplayTag& Trigger) {
    return {};
}

bool UPRGameData::StatAddUniqueItem(const FGameplayTag ItemId) {
    return {};
}

void UPRGameData::StatAddKill(const FGameplayTag NPCTag, const FGameplayTag weaponTag) {
}

void UPRGameData::StatAddDeath(const FGameplayTag KillerTag) {
}

bool UPRGameData::SetTrigger(const FGameplayTag& Trigger) {
    return {};
}

void UPRGameData::SetPlayerLevel(const int32 PlayerLevel) {
}

void UPRGameData::SaveSleepLocation(const FGameplayTag Level, const FVector Location) {
}

void UPRGameData::SaveDecorItemTransform(const FString DecorId, const FTransform Transform) {
}

void UPRGameData::SaveDecorItemDestroyed(const FString DecorId) {
}

void UPRGameData::SaveDeathLocation(const FGameplayTag Level, const FVector Location) {
}

void UPRGameData::ResetGameData() {
}

void UPRGameData::RemoveSleepLocation(const FGameplayTag Level) {
}

void UPRGameData::RemoveDeathLocation(const FGameplayTag Level) {
}

void UPRGameData::PrintMissions(const FString& Message) {
}

void UPRGameData::PrintInventory(const FString& Message) {
}

void UPRGameData::PrintData(const FString& Message) {
}

void UPRGameData::PrepareNewGame(const FRadiusGameDifficulty NewDifficulty, const bool bIronman, const bool bSkipTutorial, const bool bStartupConfig, const TArray<FGameplayTag> Triggers) {
}

void UPRGameData::OnPlayerLevelChanged(int32 PlayerLevel) {
}

void UPRGameData::OnObjectiveChange(UMissionData* MissionData, UMissionAbstractObjectiveData* Objective) {
}

void UPRGameData::OnMissionChange(UMissionData* MissionData) {
}

void UPRGameData::OnItemTaken(UInventoryItem* Item) {
}

void UPRGameData::OnItemStored(UInventoryItem* Item) {
}

bool UPRGameData::IsManOfHisWord() const {
    return {};
}

bool UPRGameData::IsKatyaMonologueInvalid(const FGameplayTag& Tag, const bool bIgnoreConditions) {
    return {};
}

bool UPRGameData::IsJournalGroupHasNewNotes(EJournalGroup Group) const {
    return {};
}

bool UPRGameData::HasMoney(const int32 Amount) const {
    return {};
}

FString UPRGameData::GetUID() {
    return {};
}

void UPRGameData::GetSpawnSaveData(USpawnerGameData*& SpawnSaveData) {
}

bool UPRGameData::GetSleepLocation(const FGameplayTag Level, FVector& Location) const {
    return {};
}

float UPRGameData::GetSecondsPassed() const {
    return {};
}

float UPRGameData::GetSecondsLastTide() const {
    return {};
}

float UPRGameData::GetRealSecondsToTide() {
    return {};
}

float UPRGameData::GetPlaytimeSeconds() const {
    return {};
}

float UPRGameData::GetPlaytimeMinutes() const {
    return {};
}

int32 UPRGameData::GetPlayerLevel() const {
    return {};
}

void UPRGameData::GetMapRenderTarget(const FGameplayTag LevelTag, UTextureRenderTarget2D*& RenderTarget) {
}

TArray<FNoteData> UPRGameData::GetJournalGroupNotes(EJournalGroup Group) {
    return {};
}

float UPRGameData::GetGameSecondsToTide() {
    return {};
}

void UPRGameData::GetGameData(UPRGameData*& GameData) {
}

EPRGameDifficultyPreset UPRGameData::GetDifficultyPreset() const {
    return {};
}

void UPRGameData::GetDecorItemTransform(const FString DecorId, FTransform& Transform, bool& bDestroyed, bool& bSuccess) {
}

bool UPRGameData::GetDeathLocation(const FGameplayTag Level, FVector& Location) const {
    return {};
}

void UPRGameData::FillFrom(UPRGameData* Other) {
}

void UPRGameData::DumpData(const FString& Message) {
}

bool UPRGameData::CheckTrigger(const FGameplayTag& Trigger) {
    return {};
}

void UPRGameData::CheckTideTriggers() {
}

bool UPRGameData::CheckMarker(const FString Marker) {
    return {};
}

void UPRGameData::CheckGameTriggers() {
}

void UPRGameData::ChangeMoney(const int32 ChangeBy, const TArray<FString>& AnalyticsParams) {
}

bool UPRGameData::ChangeGameDifficulty(const FRadiusGameDifficulty Value) {
    return {};
}

void UPRGameData::ApplyTideReset() {
}

