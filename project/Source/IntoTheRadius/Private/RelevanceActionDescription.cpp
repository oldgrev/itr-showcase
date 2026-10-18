#include "RelevanceActionDescription.h"
#include "ITRDefaults.h"

URelevanceActionDescription::URelevanceActionDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.RelevanceActionDescription"));
}

