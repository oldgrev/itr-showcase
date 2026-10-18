#pragma once

#include "CoreMinimal.h"
#include "EConsumableType.generated.h"

UENUM(BlueprintType)
enum class EConsumableType : uint8 {
    Food = 0,
    Healing = 1,
    Stimulator = 2,
};
