#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRCondition_IntCheck.h"
#include "PRCondition_StashesOpenedCheck.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCondition_StashesOpenedCheck : public UPRCondition_IntCheck {
    GENERATED_BODY()
public:
    UPRCondition_StashesOpenedCheck(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> StashTypes;
};
