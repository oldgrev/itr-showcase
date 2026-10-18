#include "PRCondition_Trigger.h"
#include "ITRDefaults.h"

UPRCondition_Trigger::UPRCondition_Trigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("Trigger.TagName"), TEXT("None"));
}

