#include "AnomalyDiscoverCriteriaDescription.h"
#include "ITRDefaults.h"

UAnomalyDiscoverCriteriaDescription::UAnomalyDiscoverCriteriaDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.AnomalyDiscoverCriteriaDescription"));
}

