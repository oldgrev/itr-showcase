#pragma once

#include "CoreMinimal.h"
#include "PRCondition_Mission.h"
#include "PRCondition_MissionSuccessfullyFinished.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_MissionSuccessfullyFinished : public UPRCondition_Mission {
    GENERATED_BODY()
public:
    UPRCondition_MissionSuccessfullyFinished(const FObjectInitializer& ObjectInitializer);

};
