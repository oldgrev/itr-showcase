#include "MissionKillNPCObjectiveConfig.h"
#include "ITRDefaults.h"

UMissionKillNPCObjectiveConfig::UMissionKillNPCObjectiveConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("SpawnNPCsRadius"), (double)1000);
}

