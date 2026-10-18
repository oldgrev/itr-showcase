#pragma once

#include "CoreMinimal.h"
#include "EOverlayState.generated.h"

UENUM(BlueprintType)
enum class EOverlayState : uint8 {
    Default = 0,
    Masculine = 1,
    Feminine = 2,
    Injured = 3,
    HandsTied = 4,
    Rifle = 5,
    Pistol1H = 6,
    Pistol2H = 7,
    Bow = 8,
    Torch = 9,
    Binoculars = 10,
    Box = 11,
    Barrel = 12,
};
