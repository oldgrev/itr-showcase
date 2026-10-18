#pragma once

#include "CoreMinimal.h"
#include "EPRPlatformType.generated.h"

UENUM(BlueprintType)
enum class EPRPlatformType : uint8 {
    Unknown = 0,
    Oculus = 1,
    Steam = 2,
    Quest = 3,
    Pico = 4,
};
