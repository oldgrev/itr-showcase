#pragma once

#include "CoreMinimal.h"
#include "MathCondition_Int.h"
#include "MathCondition_Int_MoreThan.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMathCondition_Int_MoreThan : public UMathCondition_Int {
    GENERATED_BODY()
public:
    UMathCondition_Int_MoreThan(const FObjectInitializer& ObjectInitializer);

};
