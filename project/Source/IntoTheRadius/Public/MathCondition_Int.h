#pragma once

#include "CoreMinimal.h"
#include "MathCondition.h"
#include "MathCondition_Int.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMathCondition_Int : public UMathCondition {
    GENERATED_BODY()
public:
    UMathCondition_Int(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 Value;
};
