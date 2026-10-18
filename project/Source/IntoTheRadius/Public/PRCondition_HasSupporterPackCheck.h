#pragma once

#include "CoreMinimal.h"
#include "PRCondition.h"
#include "PRCondition_HasSupporterPackCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_HasSupporterPackCheck : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_HasSupporterPackCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bValue;
};
