#pragma once

#include "CoreMinimal.h"
#include "FurnitureData.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FFurnitureData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, FTransform> SocketTransform;
    FFurnitureData();
    ~FFurnitureData();
};
