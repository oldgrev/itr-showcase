#include "MissionFetchItemsObjectiveConfig.h"
#include "ITRDefaults.h"

UMissionFetchItemsObjectiveConfig::UMissionFetchItemsObjectiveConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("SpawnItems"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("SpawnRadiusForOnePoint"), (double)500);
}

