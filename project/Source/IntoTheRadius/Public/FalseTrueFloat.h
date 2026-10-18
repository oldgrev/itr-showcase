#pragma once

#include "CoreMinimal.h"
#include "FalseTrueFloat.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FFalseTrueFloat {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FalseValue;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TrueValue;
    FFalseTrueFloat();
};
