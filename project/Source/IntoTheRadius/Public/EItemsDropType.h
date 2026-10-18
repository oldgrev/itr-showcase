#pragma once

#include "CoreMinimal.h"
#include "EItemsDropType.generated.h"

UENUM(BlueprintType)
enum class EItemsDropType : uint8 {
    Backpack = 0,
    All = 1,
};
