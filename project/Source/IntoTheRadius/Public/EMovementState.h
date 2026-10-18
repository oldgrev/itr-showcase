#pragma once

#include "CoreMinimal.h"
#include "EMovementState.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8 {
    None = 0,
    Grounded = 1,
    InAir = 2,
    Mantling = 3,
    Ragdoll = 4,
};
