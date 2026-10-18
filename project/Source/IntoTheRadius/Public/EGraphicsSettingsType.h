#pragma once

#include "CoreMinimal.h"
#include "EGraphicsSettingsType.generated.h"

UENUM(BlueprintType)
enum class EGraphicsSettingsType : uint8 {
    ViewDistance = 0,
    ShadowQuality = 1,
    FoliageDensity = 2,
    Effects = 3,
    Textures = 4,
    Geometry = 5,
};
