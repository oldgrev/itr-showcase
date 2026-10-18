#pragma once

#include "CoreMinimal.h"
#include "EInventoryMode.generated.h"

UENUM(BlueprintType)
enum class EInventoryMode : uint8 {
    None = 0,
    Normal = 1,
    Dressing = 2,
};
