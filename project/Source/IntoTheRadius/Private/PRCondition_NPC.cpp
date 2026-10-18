#include "PRCondition_NPC.h"
#include "ITRDefaults.h"

UPRCondition_NPC::UPRCondition_NPC(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NPCConfigID.TagName"), TEXT("None"));
}

