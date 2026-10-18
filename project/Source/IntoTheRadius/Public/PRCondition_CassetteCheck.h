#pragma once

#include "CoreMinimal.h"
#include "PRCondition_Trigger.h"
#include "PRCondition_CassetteCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_CassetteCheck : public UPRCondition_Trigger {
    GENERATED_BODY()
public:
    UPRCondition_CassetteCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool PassedCheck;
};
