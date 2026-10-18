#include "MissionKillNPCObjectiveData.h"
#include "ITRDefaults.h"

UMissionKillNPCObjectiveData::UMissionKillNPCObjectiveData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("SpawnNPCsRadius"), (double)1000);
}

FString UMissionKillNPCObjectiveData::PointSpawnerID(FGameplayTag pointTag) {
    return {};
}

void UMissionKillNPCObjectiveData::MarkPointCleared(FGameplayTag pointTag) {
}

