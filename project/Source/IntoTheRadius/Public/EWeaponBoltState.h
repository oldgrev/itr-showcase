#pragma once

#include "CoreMinimal.h"
#include "EWeaponBoltState.generated.h"

UENUM(BlueprintType)
enum class EWeaponBoltState : uint8 {
    Closed = 0,
    Rotating = 1,
    HalfWay = 2,
    Sliding = 3,
    Opened = 4,
};
