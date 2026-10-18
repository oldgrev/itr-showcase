#pragma once

#include "CoreMinimal.h"
#include "PRCondition.h"
#include "PRCondition_ORCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_ORCheck : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_ORCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> ORConditions;
};
