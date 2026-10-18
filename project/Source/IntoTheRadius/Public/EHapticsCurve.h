#pragma once

#include "CoreMinimal.h"
#include "EHapticsCurve.generated.h"

UENUM(BlueprintType)
enum class EHapticsCurve : uint8 {
    Interact = 0,
    FirePistol = 1,
    Grab = 2,
};
