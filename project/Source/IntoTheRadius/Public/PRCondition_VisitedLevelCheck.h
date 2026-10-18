#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRCondition.h"
#include "PRCondition_VisitedLevelCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_VisitedLevelCheck : public UPRCondition {
    GENERATED_BODY()
public:
    UPRCondition_VisitedLevelCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag LevelTag;
};
