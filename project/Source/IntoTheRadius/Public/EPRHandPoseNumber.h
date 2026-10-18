#pragma once

#include "CoreMinimal.h"
#include "EPRHandPoseNumber.generated.h"

UENUM(BlueprintType)
enum class EPRHandPoseNumber : uint8 {
    Pose1 = 0,
    Pose2 = 1,
    Pose3 = 2,
    Pose4 = 3,
    Pose5 = 4,
    Pose6 = 5,
    Pose7 = 6,
    Pose8 = 7,
    Pose9 = 8,
    Pose10 = 9,
    Count = 10,
};
