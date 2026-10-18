#include "PRCommonGameData.h"
#include "ITRDefaults.h"

UPRCommonGameData::UPRCommonGameData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::SetNum(GetClass(), this, TEXT("ObtainedWeapons.GameplayTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("ObtainedWeapons.ParentTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("FinishedMissions.GameplayTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("FinishedMissions.ParentTags"), 0);
}

void UPRCommonGameData::SetTrigger(const FGameplayTag Tag) {
}

void UPRCommonGameData::SaveShootingRun(const float RunTime, const int32 Scores, const int32 Hits, const int32 Misses, const int32 GrenadeKills) {
}

void UPRCommonGameData::OnMissionChange(UMissionData* MissionData) {
}

void UPRCommonGameData::OnItemTaken(UInventoryItem* Item) {
}

bool UPRCommonGameData::IsWeaponUnlocked(const FGameplayTag Tag) {
    return {};
}

void UPRCommonGameData::Initialize() {
}

int32 UPRCommonGameData::IncrementGuitarPlayCount() {
    return {};
}

bool UPRCommonGameData::GetTrigger(const FGameplayTag Tag) {
    return {};
}

float UPRCommonGameData::GetTotalPlaytimeMinutes() {
    return {};
}

void UPRCommonGameData::GetCommonGameData(UPRCommonGameData*& Data) {
}

