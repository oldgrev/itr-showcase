#pragma once

#include "CoreMinimal.h"
#include "AccuracyParameters.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FAccuracyParameters {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AccuracyMax;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AccuracyMultiplier;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AccuracyRunCoefficient;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AccuracyOneHandCoefficient;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AccuracyDurabilityCoefficient;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AccuracyAutoFireCoefficient;
    FAccuracyParameters();
};
