#include "MissionTutorialObjectiveData.h"
#include "ITRDefaults.h"

UMissionTutorialObjectiveData::UMissionTutorialObjectiveData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("SequencerID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("MapPoint.TagName"), TEXT("None"));
}

