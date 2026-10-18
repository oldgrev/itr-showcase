#include "PlayerViewportCriteriaDescription.h"
#include "ITRDefaults.h"

UPlayerViewportCriteriaDescription::UPlayerViewportCriteriaDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.PlayerViewportCriteriaDescription"));
}

