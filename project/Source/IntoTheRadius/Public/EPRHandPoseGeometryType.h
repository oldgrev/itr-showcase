#pragma once

#include "CoreMinimal.h"
#include "EPRHandPoseGeometryType.generated.h"

UENUM(BlueprintType)
enum class EPRHandPoseGeometryType : uint8 {
    Point = 0,
    Spline = 1,
    Count = 2,
};
