#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MissionTriggersConfig.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FMissionTriggersConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> TriggersToSet;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> TriggersToUnset;
    FMissionTriggersConfig();
    ~FMissionTriggersConfig();
};
