#pragma once

#include "CoreMinimal.h"
#include "PRCondition_NPC.h"
#include "PRCondition_NPCKilled.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_NPCKilled : public UPRCondition_NPC {
    GENERATED_BODY()
public:
    UPRCondition_NPCKilled(const FObjectInitializer& ObjectInitializer);

};
