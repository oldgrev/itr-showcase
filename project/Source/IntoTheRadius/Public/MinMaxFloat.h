#pragma once

#include "CoreMinimal.h"
#include "MinMaxFloat.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FMinMaxFloat {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Min;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Max;
    FMinMaxFloat();
};
