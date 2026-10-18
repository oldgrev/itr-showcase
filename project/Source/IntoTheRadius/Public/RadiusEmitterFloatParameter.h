#pragma once

#include "CoreMinimal.h"
#include "RadiusEmitterFloatParameter.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRadiusEmitterFloatParameter {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FName Name;
    UPROPERTY(BlueprintReadWrite)
    float Value;
    FRadiusEmitterFloatParameter();
};
