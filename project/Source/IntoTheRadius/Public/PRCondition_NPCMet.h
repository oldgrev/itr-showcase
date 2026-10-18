#pragma once

#include "CoreMinimal.h"
#include "PRCondition_NPC.h"
#include "PRCondition_NPCMet.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_NPCMet : public UPRCondition_NPC {
    GENERATED_BODY()
public:
    UPRCondition_NPCMet(const FObjectInitializer& ObjectInitializer);

};
