#pragma once

#include "CoreMinimal.h"
#include "EStorageDoorState.generated.h"

UENUM(BlueprintType)
enum class EStorageDoorState : uint8 {
    Closed = 0,
    Opened = 1,
    Gripping = 10,
    Lerping = 11,
};
