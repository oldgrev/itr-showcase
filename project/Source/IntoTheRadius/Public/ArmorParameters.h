#pragma once

#include "CoreMinimal.h"
#include "EDamageCategory.h"
#include "ArmorParameters.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FArmorParameters {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TMap<EDamageCategory, float> ArmorCoefficients;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AdditionalNoiseCoefficient;
    FArmorParameters();
    ~FArmorParameters();
};
