#pragma once

#include "CoreMinimal.h"
#include "MathCondition.h"
#include "MathCondition_Float.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMathCondition_Float : public UMathCondition {
    GENERATED_BODY()
public:
    UMathCondition_Float(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Value;
};
