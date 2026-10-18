#pragma once

#include "CoreMinimal.h"
#include "AnomalyData.h"
#include "ItemGameData.h"
#include "SpawnGameData.h"
#include "AnomalyFieldData.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FAnomalyFieldData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FAnomalyData> AnomalyData;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FSpawnGameData> ArtifactData;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FItemGameData> ItemData;
    FAnomalyFieldData();
    ~FAnomalyFieldData();
};
