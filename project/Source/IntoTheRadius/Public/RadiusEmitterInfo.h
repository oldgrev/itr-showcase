#pragma once

#include "CoreMinimal.h"
#include "RadiusEmitterParams.h"
#include "RadiusEmitterInfo.generated.h"

class UParticleSystem;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRadiusEmitterInfo {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    UParticleSystem* Template;
    UPROPERTY(BlueprintReadWrite)
    FVector ReflectionVector;
    UPROPERTY(BlueprintReadWrite)
    FRadiusEmitterParams Parameters;
    FRadiusEmitterInfo();
    ~FRadiusEmitterInfo();
};
