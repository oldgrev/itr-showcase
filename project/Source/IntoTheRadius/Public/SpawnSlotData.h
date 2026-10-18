#pragma once

#include "CoreMinimal.h"
#include "ItemGameData.h"
#include "SpawnSlotData.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FSpawnSlotData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsEmpty;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsSpawned;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FItemGameData> ItemsData;
    FSpawnSlotData();
    ~FSpawnSlotData();
};
