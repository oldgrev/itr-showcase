#pragma once

#include "CoreMinimal.h"
#include "NPCGameData.h"
#include "NPCDataMap.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FNPCDataMap {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FString, FNPCGameData> DataMap;
    FNPCDataMap();
    ~FNPCDataMap();
};
