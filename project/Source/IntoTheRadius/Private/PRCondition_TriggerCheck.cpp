#include "PRCondition_TriggerCheck.h"
#include "ITRDefaults.h"

UPRCondition_TriggerCheck::UPRCondition_TriggerCheck(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PassedCheck"), true);
}

