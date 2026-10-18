#include "PRVRGripSMComponent.h"
#include "ITRDefaults.h"

UPRVRGripSMComponent::UPRVRGripSMComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("Stiffness"), (double)1500);
    ITRDefaults::Set(GetClass(), this, TEXT("Damping"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("BreakDistance"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("GripPriority"), (double)1);
}

