#pragma once

#include "CoreMinimal.h"
#include "EMapMarker.generated.h"

UENUM(BlueprintType)
enum class EMapMarker : uint8 {
    None = 0,
    MissionStart = 10,
    MissionPrimary = 11,
    MissionSecondary = 12,
    MissionHint = 13,
    LastDeath = 20,
    LastCamp = 21,
    Custom_1 = 30,
    PlayerPosition = 40,
    GatePosition = 41,
    GateShortcut = 42,
    GateHub = 43,
};
