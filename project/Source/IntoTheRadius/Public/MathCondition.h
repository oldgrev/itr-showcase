#pragma once

#include "CoreMinimal.h"
#include "MathCondition.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew)
class INTOTHERADIUS_API UMathCondition : public UObject {
    GENERATED_BODY()
public:
    UMathCondition(const FObjectInitializer& ObjectInitializer);

};
