#include "MissionAbstractObjectiveData.h"

UMissionAbstractObjectiveData::UMissionAbstractObjectiveData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UMissionAbstractObjectiveData::HaveDelivery() {
    return {};
}

int32 UMissionAbstractObjectiveData::GetRewardMoney() const {
    return {};
}

FText UMissionAbstractObjectiveData::GetObjectiveShortName() {
    return {};
}

FText UMissionAbstractObjectiveData::GetObjectiveLongName() {
    return {};
}

TArray<FGameplayTag> UMissionAbstractObjectiveData::GetMissionPoints() {
    return {};
}

FString UMissionAbstractObjectiveData::GetDeliveryCountString() {
    return {};
}

int32 UMissionAbstractObjectiveData::GetDeliveryCountObjectives() {
    return {};
}

FString UMissionAbstractObjectiveData::GetCountString() {
    return {};
}

int32 UMissionAbstractObjectiveData::GetCountObjectives() {
    return {};
}

void UMissionAbstractObjectiveData::CollectDeliveryTags(TArray<FGameplayTag>& DeliveryTags) {
}

bool UMissionAbstractObjectiveData::CheckObjectiveCompletion() {
    return {};
}

