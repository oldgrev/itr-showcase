#include "CoverBTTask.h"
#include "ITRDefaults.h"

UCoverBTTask::UCoverBTTask(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::SetNum(GetClass(), this, TEXT("OutputVector.AllowedTypes"), 0);
    ITRDefaults::Set(GetClass(), this, TEXT("OutputVector.SelectedKeyName"), TEXT("None"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("OutputVector.SelectedKeyType"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("OutputVector.SelectedKeyID"), (double)255);
    ITRDefaults::Set(GetClass(), this, TEXT("OutputVector.bNoneIsAllowedValue"), false);
    ITRDefaults::SetNum(GetClass(), this, TEXT("TargetLocation.AllowedTypes"), 0);
    ITRDefaults::Set(GetClass(), this, TEXT("TargetLocation.SelectedKeyName"), TEXT("None"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("TargetLocation.SelectedKeyType"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("TargetLocation.SelectedKeyID"), (double)255);
    ITRDefaults::Set(GetClass(), this, TEXT("TargetLocation.bNoneIsAllowedValue"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxSearchIteration"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SearchRadius"), (double)4000);
    ITRDefaults::Set(GetClass(), this, TEXT("MinDistanceToTarget"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("bDoPathLengthCheck"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxPathLength"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("bDoSquadDistanceCheck"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("MinSquadDistance"), (double)2000);
}

void UCoverBTTask::OnQueryComplete(FNpcPointQueryResult Result) {
}

