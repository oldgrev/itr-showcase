#include "PRCheatManager.h"

UPRCheatManager::UPRCheatManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UPRCheatManager::UnlockAllWeapons() {
}

void UPRCheatManager::ToggleProjectileDraw() {
}

void UPRCheatManager::SpawnItem(const FString Tag) {
}

void UPRCheatManager::ShowRevision() {
}

void UPRCheatManager::SetSkipTutorial(bool b_new_skip) {
}

void UPRCheatManager::SecurityLevel(const int32 Level) {
}

void UPRCheatManager::RIP() const {
}

void UPRCheatManager::ResetTideTimer() const {
}

void UPRCheatManager::RefillAmmoContainer(UInventoryItem* Item) const {
}

void UPRCheatManager::RefillAmmo() const {
}

void UPRCheatManager::RaiseCrashReport() {
}

void UPRCheatManager::PrintActors() {
}

bool UPRCheatManager::IsProjectileDraw() const {
    return {};
}

void UPRCheatManager::GiveMeTheWeapon(const FString Tag) {
}

void UPRCheatManager::GiveMeTheMoney(const int32 Amount) {
}

void UPRCheatManager::GiveMeTheDurability(const int32 Value) {
}

void UPRCheatManager::GiveMeTheBullets() {
}

bool UPRCheatManager::GetSkipTutorial() const {
    return {};
}

void UPRCheatManager::GetMission(const FGameplayTag MissionInstanceId, UMissionData*& MissionData) const {
}

TArray<FGameplayTag> UPRCheatManager::GetChildTags(const FGameplayTag parentTag) {
    return {};
}

UInventoryItem* UPRCheatManager::DoSpawnItem(const FGameplayTag Tag) {
    return {};
}

void UPRCheatManager::ChangeHealth(const int32 Delta) const {
}

void UPRCheatManager::AddMission(UMissionData* MissionData) {
}

