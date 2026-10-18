#pragma once

#include "CoreMinimal.h"
#include "PRCondition_IntCheck.h"
#include "PRCondition_TotalFinishedCountCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_TotalFinishedCountCheck : public UPRCondition_IntCheck {
    GENERATED_BODY()
public:
    UPRCondition_TotalFinishedCountCheck(const FObjectInitializer& ObjectInitializer);

};
