#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRCondition.h"
#include "PRCondition_NPC.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_NPC : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_NPC(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag NPCConfigID;
};
