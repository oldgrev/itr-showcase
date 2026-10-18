#pragma once

#include "CoreMinimal.h"
#include "RadiusEmitterParams.h"
#include "RadiusNiagaraEmitterInfo.generated.h"

class UNiagaraSystem;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRadiusNiagaraEmitterInfo {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    UNiagaraSystem* Template;
    UPROPERTY(BlueprintReadWrite)
    FRadiusEmitterParams Parameters;
    FRadiusNiagaraEmitterInfo();
    ~FRadiusNiagaraEmitterInfo();
};
