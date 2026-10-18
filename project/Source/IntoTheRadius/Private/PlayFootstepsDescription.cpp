#include "PlayFootstepsDescription.h"
#include "ITRDefaults.h"

UPlayFootstepsDescription::UPlayFootstepsDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.PlayFootstepsDescription"));
}

