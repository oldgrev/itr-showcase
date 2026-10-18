#pragma once

#include "CoreMinimal.h"
#include "EnemySenseMultiplier.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FEnemySenseMultiplier {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float HearingRadiusRange;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float SightDistanceRange;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float SightAnglesHorizontal;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float SightAnglesVertical;
    FEnemySenseMultiplier();
};
