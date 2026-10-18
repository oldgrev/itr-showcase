#pragma once

#include "CoreMinimal.h"
#include "ERotationMode.generated.h"

UENUM(BlueprintType)
enum class ERotationMode : uint8 {
    VelocityDirection = 0,
    LookingDirection = 1,
    Aiming = 2,
};
