#pragma once

#include "CoreMinimal.h"
#include "EPlayerControlAction.generated.h"

UENUM(BlueprintType)
enum class EPlayerControlAction : uint8 {
    InteractLeft = 0,
    InteractRight = 1,
    GrabLeft = 2,
    GrabRight = 3,
    Move = 4,
    Turn = 5,
    Sprint = 6,
    Menu = 7,
    FireSelectorLeft = 10,
    FireSelectorRight = 11,
    EjectMagLeft = 12,
    EjectMagRight = 13,
};
