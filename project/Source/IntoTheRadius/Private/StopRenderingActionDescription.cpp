#include "StopRenderingActionDescription.h"
#include "ITRDefaults.h"

UStopRenderingActionDescription::UStopRenderingActionDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.StopRenderingActionDescription"));
}

