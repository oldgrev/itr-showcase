#include "PRCondition_Mission.h"
#include "ITRDefaults.h"

UPRCondition_Mission::UPRCondition_Mission(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("MissionConfigId.TagName"), TEXT("None"));
}

