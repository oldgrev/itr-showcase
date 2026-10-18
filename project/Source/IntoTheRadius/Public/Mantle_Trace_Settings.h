#pragma once

#include "CoreMinimal.h"
#include "Mantle_Trace_Settings.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FMantle_Trace_Settings {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxLedgeHeight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinLedgeHeight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ReachDistance;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ForwardTraceRadius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DownwardTraceRadius;
    FMantle_Trace_Settings();
};
