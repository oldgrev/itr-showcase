#include "MissionData.h"
#include "ITRDefaults.h"

UMissionData::UMissionData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("ConfigID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("Abortable"), true);
}

void UMissionData::SetTutorStep(FGameplayTag SequencerID, int32 step) {
}

bool UMissionData::HaveDelivery() {
    return {};
}

void UMissionData::GetTotalReward(const bool FinishedOnly, int32& MoneyReward, int32& PlayerLevel) {
}

float UMissionData::GetTimeTillAbortAvailable() {
    return {};
}

FString UMissionData::GetStashUID(UMissionAbstractObjectiveData* Objective, FGameplayTag Tag) const {
    return {};
}

TArray<FGameplayTag> UMissionData::GetMissionPoints() {
    return {};
}

FText UMissionData::GetMissionName() const {
    return {};
}

FText UMissionData::GetMissionDescription() const {
    return {};
}

FGameplayTag UMissionData::GetMissionCategoryID() const {
    return {};
}

FGameplayTag UMissionData::GetMainObjectivePoint() const {
    return {};
}

FGameplayTag UMissionData::GetMainObjectiveLevel() const {
    return {};
}

FString UMissionData::GetItemUID(UMissionAbstractObjectiveData* Objective, int32 Index) const {
    return {};
}

void UMissionData::GetDuration(bool& bHaveDuration, FString& FinishDateString) {
}

bool UMissionData::FinishObjective(UMissionAbstractObjectiveData* Objective, bool bIgnoreTutorialDelivery) {
    return {};
}

bool UMissionData::FinishAllObjectives(bool bIgnoreTutorialDelivery) {
    return {};
}

bool UMissionData::CheckPrimaryObjectivesCompleted() {
    return {};
}

void UMissionData::CheckDelivery(TArray<AActor*> ItemActors, bool bFinishObjectives, bool& bSuccess, TArray<AActor*>& ExcessiveActors) {
}

void UMissionData::CheckCompletion(bool& bCompleted) {
}

