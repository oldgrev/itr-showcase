#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "StaticMeshDataForInstanced.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FStaticMeshDataForInstanced {
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere)
    FVector LocationsAccumulated;
    UPROPERTY(VisibleAnywhere)
    uint8 CountOfStaticMeshInstances;
    UPROPERTY(EditAnywhere)
    TArray<TSoftObjectPtr<UMaterialInterface>> MaterialsUsedByStaticMesh;
    UPROPERTY(EditAnywhere)
    float MaxCullDistance;
    UPROPERTY(EditAnywhere)
    FName CollisionProfileName;
    UPROPERTY(EditAnywhere)
    bool EnableCollisionOverlapEvents;
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EComponentMobility::Type> ComponentMobility;
    FStaticMeshDataForInstanced();
    ~FStaticMeshDataForInstanced();
};
