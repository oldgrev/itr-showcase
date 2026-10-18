#include "PRCondition_CassetteCheck.h"
#include "ITRDefaults.h"

UPRCondition_CassetteCheck::UPRCondition_CassetteCheck(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PassedCheck"), true);
}

