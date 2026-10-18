#include "BTS_UpdateTargetLocation.h"
#include "ITRDefaults.h"

UBTS_UpdateTargetLocation::UBTS_UpdateTargetLocation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NodeName"), TEXT("Update Target Location"));
    ITRDefaults::SetNum(GetClass(), this, TEXT("BlackboardKey.AllowedTypes"), 0);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.SelectedKeyName"), TEXT("TargetLocation"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("BlackboardKey.SelectedKeyType"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.SelectedKeyID"), (double)255);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.bNoneIsAllowedValue"), false);
}

