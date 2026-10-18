#pragma once

#include "CoreMinimal.h"
#include "MapData.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FMapData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<uint8> Data;
    FMapData();
    ~FMapData();
};
