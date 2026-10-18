#pragma once

#include "CoreMinimal.h"
#include "MinMaxInt.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FMinMaxInt {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Min;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Max;
    FMinMaxInt();
};
