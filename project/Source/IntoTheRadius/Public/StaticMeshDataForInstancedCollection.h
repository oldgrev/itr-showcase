#pragma once

#include "CoreMinimal.h"
#include "StaticMeshDataForInstanced.h"
#include "StaticMeshDataForInstancedCollection.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FStaticMeshDataForInstancedCollection {
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere)
    TArray<FStaticMeshDataForInstanced> StaticMeshDataForInstanced;
    FStaticMeshDataForInstancedCollection();
    ~FStaticMeshDataForInstancedCollection();
};
