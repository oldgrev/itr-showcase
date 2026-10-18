#pragma once

#include "CoreMinimal.h"
#include "EDigitsCompareMethod.generated.h"

UENUM(BlueprintType)
enum class EDigitsCompareMethod : uint8 {
    EqualTo = 0,
    NotEqualTo = 1,
    GreaterThanOrEqualTo = 2,
    LessThanOrEqualTo = 3,
    GreaterThan = 4,
    LessThan = 5,
};
