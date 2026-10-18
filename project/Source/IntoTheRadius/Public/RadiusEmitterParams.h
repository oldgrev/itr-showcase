#pragma once

#include "CoreMinimal.h"
#include "RadiusEmitterIntParameter.h"
#include "RadiusEmitterVectorParameter.h"
#include "RadiusEmitterParams.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRadiusEmitterParams {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    TArray<FRadiusEmitterVectorParameter> VectorParameters;
    UPROPERTY(BlueprintReadWrite)
    TArray<FRadiusEmitterIntParameter> FloatParameters;
    UPROPERTY(BlueprintReadWrite)
    TArray<FRadiusEmitterIntParameter> IntParameters;
    FRadiusEmitterParams();
    ~FRadiusEmitterParams();
};
