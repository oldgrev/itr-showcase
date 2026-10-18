#pragma once

#include "CoreMinimal.h"
#include "PRCondition_IntCheck.h"
#include "PRCondition_ActiveCountCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_ActiveCountCheck : public UPRCondition_IntCheck {
    GENERATED_BODY()
public:
    UPRCondition_ActiveCountCheck(const FObjectInitializer& ObjectInitializer);

};
