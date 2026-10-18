#pragma once

#include "CoreMinimal.h"
#include "Mantle_Params.generated.h"

class UAnimMontage;
class UCurveVector;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FMantle_Params {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UAnimMontage* AnimMontage;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UCurveVector* PositionOrCorrectionCurve;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartingPosition;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayRate;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector StartingOffset;
    FMantle_Params();
};
