#include "RelevanceCriteriaDescription.h"
#include "ITRDefaults.h"

URelevanceCriteriaDescription::URelevanceCriteriaDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.RelevanceCriteriaDescription"));
}

