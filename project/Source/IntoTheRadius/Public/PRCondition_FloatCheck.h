#pragma once

#include "CoreMinimal.h"
#include "PRCondition.h"
#include "PRCondition_FloatCheck.generated.h"

class UMathCondition_Float;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_FloatCheck : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_FloatCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    UMathCondition_Float* ValueCheck;
};
