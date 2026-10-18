#include "ViewportNotifierDescription.h"
#include "ITRDefaults.h"

UViewportNotifierDescription::UViewportNotifierDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.ViewportNotifierDescription"));
}

