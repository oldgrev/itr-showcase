#pragma once

#include "CoreMinimal.h"
#include "EHandPose.generated.h"

UENUM(BlueprintType)
enum class EHandPose : uint8 {
    Default = 0,
    Open = 1,
    CanGrab = 3,
    GrabFull = 5,
    SolveFingers = 10,
    ConfiguredPose = 20,
    FingerPoint = 22,
    FingerPressed = 23,
    ConfiguredPoseSecondary = 30,
    ConfiguredTriggerPose = 31,
};
