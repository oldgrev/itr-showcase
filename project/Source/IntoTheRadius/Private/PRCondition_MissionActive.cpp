#include "PRCondition_MissionActive.h"
#include "ITRDefaults.h"

UPRCondition_MissionActive::UPRCondition_MissionActive(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("InProgress"), true);
}

