#pragma once

#include "CoreMinimal.h"
#include "PRCondition_Trigger.h"
#include "PRCondition_TriggerCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_TriggerCheck : public UPRCondition_Trigger {
    GENERATED_BODY()
public:
    UPRCondition_TriggerCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool PassedCheck;
};
