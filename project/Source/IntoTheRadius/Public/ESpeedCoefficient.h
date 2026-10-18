#pragma once

#include "CoreMinimal.h"
#include "ESpeedCoefficient.generated.h"

UENUM(BlueprintType)
enum class ESpeedCoefficient : uint8 {
    Default = 0,
    Anomaly = 1,
    Tide = 2,
    TutorialZone = 3,
    WaterPatch = 4,
};
