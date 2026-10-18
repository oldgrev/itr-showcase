#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TideTriggerConfig.generated.h"

class UPRCondition;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FTideTriggerConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> TriggersToSet;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> TriggersToUnset;
    FTideTriggerConfig();
    ~FTideTriggerConfig();
};
