#pragma once

#include "CoreMinimal.h"
#include "Mantle_Asset.generated.h"

class UAnimMontage;
class UCurveVector;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FMantle_Asset {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UAnimMontage* AnimMontage;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UCurveVector* PositionOrCorrectionCurve;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector StartingOffset;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LowHeight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LowPlayRate;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LowStartPosition;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float HighHeight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float HighPlayRate;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float HighStartPosition;
    FMantle_Asset();
};
