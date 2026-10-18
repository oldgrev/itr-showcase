#include "AnomalySpawnCriteriaDescription.h"
#include "ITRDefaults.h"

UAnomalySpawnCriteriaDescription::UAnomalySpawnCriteriaDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.AnomalySpawnCriteriaDescription"));
}

