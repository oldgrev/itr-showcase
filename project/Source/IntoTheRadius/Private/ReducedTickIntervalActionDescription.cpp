#include "ReducedTickIntervalActionDescription.h"
#include "ITRDefaults.h"

UReducedTickIntervalActionDescription::UReducedTickIntervalActionDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.ReducedTickIntervalActionDescription"));
    ITRDefaults::Set(GetClass(), this, TEXT("ActorTickIntervalMultiplier"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("AnimationTickIntervalMultiplier"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionTickIntervalMultiplier"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("MovementTickIntervalMultiplier"), (double)1);
}

