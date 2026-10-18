#pragma once

#include "CoreMinimal.h"
#include "PRCondition_Mission.h"
#include "PRCondition_HoursSinceMissionSuccessfullyFinished.generated.h"

class UMathCondition_Int;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_HoursSinceMissionSuccessfullyFinished : public UPRCondition_Mission {
    GENERATED_BODY()
public:
    UPRCondition_HoursSinceMissionSuccessfullyFinished(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    UMathCondition_Int* ValueCheck;
};
