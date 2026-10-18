#include "MissionFetchItemsObjectiveData.h"
#include "ITRDefaults.h"

UMissionFetchItemsObjectiveData::UMissionFetchItemsObjectiveData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("SpawnItems"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("SpawnRadiusForOnePoint"), (double)500);
}

