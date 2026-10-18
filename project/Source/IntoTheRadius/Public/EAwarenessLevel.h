#pragma once

#include "CoreMinimal.h"
#include "EAwarenessLevel.generated.h"

UENUM(BlueprintType)
enum class EAwarenessLevel : uint8 {
    None = 0,
    Low = 1,
    High = 2,
};
