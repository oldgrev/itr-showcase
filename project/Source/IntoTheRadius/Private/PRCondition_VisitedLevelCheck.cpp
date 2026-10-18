#include "PRCondition_VisitedLevelCheck.h"
#include "ITRDefaults.h"

UPRCondition_VisitedLevelCheck::UPRCondition_VisitedLevelCheck(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("LevelTag.TagName"), TEXT("None"));
}

