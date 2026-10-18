#pragma once

#include "CoreMinimal.h"
#include "MathCondition_Int.h"
#include "MathCondition_Int_MoreEqualThan.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMathCondition_Int_MoreEqualThan : public UMathCondition_Int {
    GENERATED_BODY()
public:
    UMathCondition_Int_MoreEqualThan(const FObjectInitializer& ObjectInitializer);

};
