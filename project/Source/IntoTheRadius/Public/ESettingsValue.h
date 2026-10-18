#pragma once

#include "CoreMinimal.h"
#include "ESettingsValue.generated.h"

UENUM(BlueprintType)
enum class ESettingsValue : uint8 {
    Low = 0,
    Medium = 1,
    High = 2,
};
