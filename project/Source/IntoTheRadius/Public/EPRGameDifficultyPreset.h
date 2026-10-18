#pragma once

#include "CoreMinimal.h"
#include "EPRGameDifficultyPreset.generated.h"

UENUM(BlueprintType)
enum class EPRGameDifficultyPreset : uint8 {
    Easy = 0,
    Normal = 1,
    Hard = 2,
    Custom = 3,
};
