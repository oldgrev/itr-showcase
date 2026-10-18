#pragma once

#include "CoreMinimal.h"
#include "MinimapFoliageMappingConfig.generated.h"

class UFoliageType;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FMinimapFoliageMappingConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<UFoliageType*> appliedTo;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Scale;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool rotateToMesh;
    FMinimapFoliageMappingConfig();
    ~FMinimapFoliageMappingConfig();
};
