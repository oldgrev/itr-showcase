#pragma once

#include "CoreMinimal.h"
#include "EPRHandPoseType.generated.h"

UENUM(BlueprintType)
enum class EPRHandPoseType : uint8 {
    Primary = 0,
    PrimaryTriggered = 1,
    PrimarySafety = 2,
    Secondary = 10,
    Throw = 20,
    Slide = 30,
};
