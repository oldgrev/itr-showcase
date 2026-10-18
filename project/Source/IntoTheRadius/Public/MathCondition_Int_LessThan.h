#pragma once

#include "CoreMinimal.h"
#include "MathCondition_Int.h"
#include "MathCondition_Int_LessThan.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMathCondition_Int_LessThan : public UMathCondition_Int {
    GENERATED_BODY()
public:
    UMathCondition_Int_LessThan(const FObjectInitializer& ObjectInitializer);

};
