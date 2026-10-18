#pragma once

#include "CoreMinimal.h"
#include "EDamageCategory.generated.h"

UENUM(BlueprintType)
enum class EDamageCategory : uint8 {
    None = 0,
    Physical = 1,
    Anomaly = 2,
    Environmental = 3,
    Technical = 4,
    Gas = 5,
};
