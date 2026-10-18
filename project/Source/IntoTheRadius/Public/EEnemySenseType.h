#pragma once

#include "CoreMinimal.h"
#include "EEnemySenseType.generated.h"

UENUM(BlueprintType)
enum class EEnemySenseType : uint8 {
    Reduced = 0,
    Normal = 1,
};
