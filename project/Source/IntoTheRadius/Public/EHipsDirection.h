#pragma once

#include "CoreMinimal.h"
#include "EHipsDirection.generated.h"

UENUM(BlueprintType)
enum class EHipsDirection : uint8 {
    F = 0,
    B = 1,
    RF = 2,
    RB = 3,
    LF = 4,
    LB = 5,
};
