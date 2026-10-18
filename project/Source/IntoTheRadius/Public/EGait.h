#pragma once

#include "CoreMinimal.h"
#include "EGait.generated.h"

UENUM(BlueprintType)
enum class EGait : uint8 {
    Walking = 0,
    Running = 1,
    Sprinting = 2,
};
