#pragma once

#include "CoreMinimal.h"
#include "PRCondition_IntCheck.h"
#include "PRCondition_DeathsCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_DeathsCheck : public UPRCondition_IntCheck {
    GENERATED_BODY()
public:
    UPRCondition_DeathsCheck(const FObjectInitializer& ObjectInitializer);

};
