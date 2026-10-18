#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AchievementsConfig.generated.h"

class AActor;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FAchievementsConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<TSubclassOf<AActor>> BarrelClasses;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float KillDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTagContainer LoreCassetteTags;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTagContainer ArtifactTags;
    FAchievementsConfig();
    ~FAchievementsConfig();
};
