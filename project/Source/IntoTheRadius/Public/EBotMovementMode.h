#pragma once

#include "CoreMinimal.h"
#include "EBotMovementMode.generated.h"

UENUM(BlueprintType)
enum class EBotMovementMode : uint8 {
    WalkIdle = 0,
    CrouchIdle = 1,
    Sprint = 2,
    RunIdle = 3,
    WalkAiming = 4,
    CrouchAiming = 5,
    RunAiming = 6,
};
