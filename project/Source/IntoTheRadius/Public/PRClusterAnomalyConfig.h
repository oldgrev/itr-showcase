#pragma once

#include "CoreMinimal.h"
#include "PRClusterAnomalyConfig.generated.h"

class APRAnomaly;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FPRClusterAnomalyConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Location;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<APRAnomaly> Class;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Radius;
    FPRClusterAnomalyConfig();
};
