#pragma once

#include "CoreMinimal.h"
#include "MathCondition_Float.h"
#include "MathCondition_Float_MoreEqualThan.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMathCondition_Float_MoreEqualThan : public UMathCondition_Float {
    GENERATED_BODY()
public:
    UMathCondition_Float_MoreEqualThan(const FObjectInitializer& ObjectInitializer);

};
