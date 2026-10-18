#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "PRCleanTransform.h"
#include "PRSplineData.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FPRSplineData {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRCleanTransform SplineShift;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRCleanTransform HandShiftRelatedSpline;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FSplinePoint> Points;
    FPRSplineData();
    ~FPRSplineData();
};
