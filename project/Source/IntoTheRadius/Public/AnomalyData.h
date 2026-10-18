#pragma once

#include "CoreMinimal.h"
#include "SpawnGameData.h"
#include "AnomalyData.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FAnomalyData : public FSpawnGameData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Radius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FTransform> Points;
    FAnomalyData();
    ~FAnomalyData();
};
