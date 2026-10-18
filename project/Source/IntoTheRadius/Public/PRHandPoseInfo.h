#pragma once

#include "CoreMinimal.h"
#include "EPRControllerType.h"
#include "PRCleanTransform.h"
#include "PRHandPoseConditions.h"
#include "PRSplineData.h"
#include "PRHandPoseInfo.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FPRHandPoseInfo {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<EPRControllerType, FPRCleanTransform> ItemShiftPerController;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRCleanTransform HandShift;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRCleanTransform PointShift;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRSplineData SplineData;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRHandPoseConditions HandPoseConditions;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRCleanTransform FingerThumbShift;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRCleanTransform FingerIndexShift;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRCleanTransform FingerMiddleShift;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRCleanTransform FingerRingShift;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRCleanTransform FingerPinkyShift;
    FPRHandPoseInfo();
    ~FPRHandPoseInfo();
};
