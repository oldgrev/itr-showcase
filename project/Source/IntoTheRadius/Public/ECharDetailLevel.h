#pragma once

#include "CoreMinimal.h"
#include "ECharDetailLevel.generated.h"

UENUM(BlueprintType)
enum class ECharDetailLevel : uint8 {
    Normal = 0,
    PendingDisable = 1,
    Disabled = 2,
};
