#pragma once

#include "CoreMinimal.h"
#include "PRCondition.h"
#include "PRCondition_MinimumPlayerLevelCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_MinimumPlayerLevelCheck : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_MinimumPlayerLevelCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MinimumPlayerLevel;
};
