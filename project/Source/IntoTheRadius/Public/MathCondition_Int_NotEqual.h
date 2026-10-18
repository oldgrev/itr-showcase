#pragma once

#include "CoreMinimal.h"
#include "MathCondition_Int.h"
#include "MathCondition_Int_NotEqual.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMathCondition_Int_NotEqual : public UMathCondition_Int {
    GENERATED_BODY()
public:
    UMathCondition_Int_NotEqual(const FObjectInitializer& ObjectInitializer);

};
