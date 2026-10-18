#include "StopColliderActionDescription.h"
#include "ITRDefaults.h"

UStopColliderActionDescription::UStopColliderActionDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.StopColliderActionDescription"));
}

