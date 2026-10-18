#include "MissionsManager.h"

UMissionsManager::UMissionsManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UMissionsManager::StartMissionFromIdLatent(bool& bSuccess, FGameplayTag GameplayTag, UObject* WorldContextObject, FLatentActionInfo LatentInfo) {
}

void UMissionsManager::StartMission(const FString& MissionInstanceId, bool& bSuccess, UMissionData*& MissionData) {
}

void UMissionsManager::SetSelectedMissionComplete(const FString MissionInstanceId) {
}

void UMissionsManager::ResetTutorialMissions() {
}

void UMissionsManager::OnPlayerLevelChanged(const int32 PlayerLevel) {
}

void UMissionsManager::IsMissionSelected(const FString MissionInstanceId, bool& bMissionSelected) {
}

bool UMissionsManager::IsMaxExecutingReached() {
    return {};
}

bool UMissionsManager::GetStoryMissionUnlockInfo(int32& FinishedAfterPrevStory, int32& RequiredAfterPrevStory) {
    return {};
}

void UMissionsManager::GetSelectedMissionsInState(const EMissionState State, TArray<UMissionData*>& SelectedMissions) {
}

TArray<UMissionData*> UMissionsManager::GetSelectedMissionsInProgress() {
    return {};
}

void UMissionsManager::GetSelectedMissions(TArray<UMissionData*>& SelectedMissions) {
}

UMissionsManager* UMissionsManager::GetMissionsManager() {
    return {};
}

int32 UMissionsManager::GetMissionsFinishedAfter(const FGameplayTag ConfigID, const bool bOnlySuccessful) {
    return {};
}

void UMissionsManager::GetMission(const FString& MissionInstanceId, UMissionData*& MissionData) {
}

void UMissionsManager::GetFinishedMissions(TArray<UMissionData*>& FinishedMissions) {
}

bool UMissionsManager::GetAvailableStoryMission(UMissionData*& StoryMission) {
    return {};
}

void UMissionsManager::GetActiveMissions(TMap<FGameplayTag, UMissionData*>& ActiveMissions) {
}

void UMissionsManager::GetActiveMissionOfType(const FGameplayTag& Category, UMissionData*& MissionData) {
}

bool UMissionsManager::GenerateNewMissions(bool bTide) {
    return {};
}

bool UMissionsManager::FinishMission(const FString MissionInstanceId) {
    return {};
}

void UMissionsManager::CheckActive() {
}

void UMissionsManager::AbortSelectedMission(const FString MissionInstanceId) {
}

