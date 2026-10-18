#include "ValidActorCriteriaDescription.h"
#include "ITRDefaults.h"

UValidActorCriteriaDescription::UValidActorCriteriaDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.ValidActorCriteriaDescription"));
}

