#pragma once

#include "CoreMinimal.h"
#include "CloseCombatManagerEnemyGroup.h"
#include "CloseCombatManagerConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FCloseCombatManagerConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bEnabled;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float CloseRangeRadius;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float CircleOfInterestRadius;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MinDistanceFromPlayerToReappear;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float TeleportSearchRadius;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Budget;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FCloseCombatManagerEnemyGroup> EnemyGroups;
    FCloseCombatManagerConfig();
    ~FCloseCombatManagerConfig();
};
