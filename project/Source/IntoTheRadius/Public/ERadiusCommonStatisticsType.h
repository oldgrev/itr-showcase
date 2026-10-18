#pragma once

#include "CoreMinimal.h"
#include "ERadiusCommonStatisticsType.generated.h"

UENUM(BlueprintType)
enum class ERadiusCommonStatisticsType : uint8 {
    TimePlayed = 0,
    FinishedMissions = 1,
    CollectedArtifacts = 2,
    CollectedCassettes = 3,
    CollectedWeaponPrimary = 4,
    CollectedWeaponSecondary = 5,
};
