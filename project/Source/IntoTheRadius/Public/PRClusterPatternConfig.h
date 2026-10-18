#pragma once

#include "CoreMinimal.h"
#include "PRClusterAnomalyConfig.h"
#include "PRClusterPatternConfig.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FPRClusterPatternConfig {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<FPRClusterAnomalyConfig> AnomalyPoints;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<FVector> ArtifactPoints;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FVector BlockExtent;
    FPRClusterPatternConfig();
    ~FPRClusterPatternConfig();
};
