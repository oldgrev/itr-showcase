#include "DiscoverAnomalyActionDescription.h"
#include "ITRDefaults.h"

UDiscoverAnomalyActionDescription::UDiscoverAnomalyActionDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.DiscoverAnomalyActionDescription"));
}

