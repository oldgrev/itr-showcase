#pragma once

#include "CoreMinimal.h"
#include "RadiusEmitterVectorParameter.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRadiusEmitterVectorParameter {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FName Name;
    UPROPERTY(BlueprintReadWrite)
    FVector Value;
    FRadiusEmitterVectorParameter();
};
