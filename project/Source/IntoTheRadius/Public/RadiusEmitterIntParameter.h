#pragma once

#include "CoreMinimal.h"
#include "RadiusEmitterIntParameter.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRadiusEmitterIntParameter {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FName Name;
    UPROPERTY(BlueprintReadWrite)
    int32 Value;
    FRadiusEmitterIntParameter();
};
