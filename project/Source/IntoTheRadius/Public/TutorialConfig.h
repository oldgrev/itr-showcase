#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TutorialConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FTutorialConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 PlayerLevel;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 Reward;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag TriggerTag;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag LevelTag;
    FTutorialConfig();
};
