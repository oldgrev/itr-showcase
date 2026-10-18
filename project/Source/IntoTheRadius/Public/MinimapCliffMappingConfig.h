#pragma once

#include "CoreMinimal.h"
#include "MinimapCliffMappingConfig.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FMinimapCliffMappingConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float scaleThreshold;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float scaleRatio;
    FMinimapCliffMappingConfig();
};
