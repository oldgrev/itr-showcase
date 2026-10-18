#pragma once

#include "CoreMinimal.h"
#include "TransformsTuple.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FTransformsTuple {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform First;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform Second;
    FTransformsTuple();
};
