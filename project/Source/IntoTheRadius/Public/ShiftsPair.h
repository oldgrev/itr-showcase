#pragma once

#include "CoreMinimal.h"
#include "ShiftsPair.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FShiftsPair {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FTransform LeftShift;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FTransform RightShift;
    FShiftsPair();
};
