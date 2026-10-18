#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRTriggerConfig.generated.h"

class UPRCondition;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FPRTriggerConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag Trigger;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
    FPRTriggerConfig();
    ~FPRTriggerConfig();
};
