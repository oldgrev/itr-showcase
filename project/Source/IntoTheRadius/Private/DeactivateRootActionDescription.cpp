#include "DeactivateRootActionDescription.h"
#include "ITRDefaults.h"

UDeactivateRootActionDescription::UDeactivateRootActionDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.DeactivateRootActionDescription"));
}

