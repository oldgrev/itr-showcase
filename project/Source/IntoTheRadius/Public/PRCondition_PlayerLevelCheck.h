#pragma once

#include "CoreMinimal.h"
#include "MinMaxInt.h"
#include "PRCondition.h"
#include "PRCondition_PlayerLevelCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_PlayerLevelCheck : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_PlayerLevelCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FMinMaxInt PlayerLevelRange;
};
