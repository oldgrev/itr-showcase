#pragma once

#include "CoreMinimal.h"
#include "ERadiusAchievement.generated.h"

UENUM(BlueprintType)
enum class ERadiusAchievement : uint8 {
    None = 0,
    FirstWeapon = 1,
    FirstDeath = 2,
    CompleteShootingRange = 10,
    CompleteIronman = 11,
    ClimbCrane = 20,
    KillFromDistance = 21,
    KillWithBarrel = 22,
    HitByStomper = 23,
    CollectArtifacts = 30,
    CollectLoreCassettes = 31,
};
