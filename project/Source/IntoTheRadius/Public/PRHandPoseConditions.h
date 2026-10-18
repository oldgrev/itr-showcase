#pragma once

#include "CoreMinimal.h"
#include "PRHandPoseConditions.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FPRHandPoseConditions {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxDistanceForGrip;
    FPRHandPoseConditions();
};
