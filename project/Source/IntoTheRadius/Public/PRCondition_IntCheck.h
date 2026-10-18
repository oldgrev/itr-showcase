#pragma once

#include "CoreMinimal.h"
#include "PRCondition.h"
#include "PRCondition_IntCheck.generated.h"

class UMathCondition_Int;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_IntCheck : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_IntCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    UMathCondition_Int* ValueCheck;
};
