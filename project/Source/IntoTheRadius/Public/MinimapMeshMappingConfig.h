#pragma once

#include "CoreMinimal.h"
#include "MinimapMeshMappingConfig.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FMinimapMeshMappingConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<UStaticMesh*> appliedTo;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Scale;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool rotateToMesh;
    FMinimapMeshMappingConfig();
    ~FMinimapMeshMappingConfig();
};
