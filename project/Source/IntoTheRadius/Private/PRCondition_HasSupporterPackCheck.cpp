#include "PRCondition_HasSupporterPackCheck.h"
#include "ITRDefaults.h"

UPRCondition_HasSupporterPackCheck::UPRCondition_HasSupporterPackCheck(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("bValue"), true);
}

