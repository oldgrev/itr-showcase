#pragma once

#include "CoreMinimal.h"
#include "MovementSettings.generated.h"

class UCurveFloat;
class UCurveVector;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FMovementSettings {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WalkSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RunSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SprintSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UCurveVector* MovementCurve;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UCurveFloat* RotationRateCurve;
    FMovementSettings();
};
