#pragma once

#include "CoreMinimal.h"
#include "PRCondition.h"
#include "PRCondition_MORCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_MORCheck : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_MORCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 Minimum;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
};
