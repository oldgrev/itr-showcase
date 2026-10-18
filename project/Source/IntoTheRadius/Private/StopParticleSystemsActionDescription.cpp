#include "StopParticleSystemsActionDescription.h"
#include "ITRDefaults.h"

UStopParticleSystemsActionDescription::UStopParticleSystemsActionDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.StopParticleSystemsActionDescription"));
}

