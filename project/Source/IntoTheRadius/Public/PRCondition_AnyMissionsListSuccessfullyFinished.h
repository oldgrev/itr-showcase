#pragma once

#include "CoreMinimal.h"
#include "PRCondition_MissionsList.h"
#include "PRCondition_AnyMissionsListSuccessfullyFinished.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_AnyMissionsListSuccessfullyFinished : public UPRCondition_MissionsList {
    GENERATED_BODY()
public:
    UPRCondition_AnyMissionsListSuccessfullyFinished(const FObjectInitializer& ObjectInitializer);

};
