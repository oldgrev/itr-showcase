#pragma once

#include "CoreMinimal.h"
#include "EMovementAction.generated.h"

UENUM(BlueprintType)
enum class EMovementAction : uint8 {
    None = 0,
    LowMantle = 1,
    HighMantle = 2,
    Rolling = 3,
    GettingUp = 4,
};
