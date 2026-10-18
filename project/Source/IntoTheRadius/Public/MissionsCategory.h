#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MissionsCategory.generated.h"

class UMissionNormalConfig;
class UPRCondition;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FMissionsCategory {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag CategoryID;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MaxSimultaneously;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool RestrictMaxSuccessfulPerTide;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool OnceInALife;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<UMissionNormalConfig*> CategoryMissions;
    FMissionsCategory();
    ~FMissionsCategory();
};
