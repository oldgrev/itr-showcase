#pragma once

#include "CoreMinimal.h"
#include "ShootingScores.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FShootingScores {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FDateTime Date;
    UPROPERTY(BlueprintReadOnly)
    float Time;
    UPROPERTY(BlueprintReadOnly)
    int32 Score;
    UPROPERTY(BlueprintReadOnly)
    int32 Hits;
    UPROPERTY(BlueprintReadOnly)
    int32 Misses;
    UPROPERTY(BlueprintReadOnly)
    int32 GrenadeKills;
    FShootingScores();
};
