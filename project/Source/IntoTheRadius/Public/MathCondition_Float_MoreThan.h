#pragma once

#include "CoreMinimal.h"
#include "MathCondition_Float.h"
#include "MathCondition_Float_MoreThan.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMathCondition_Float_MoreThan : public UMathCondition_Float {
    GENERATED_BODY()
public:
    UMathCondition_Float_MoreThan(const FObjectInitializer& ObjectInitializer);

};
