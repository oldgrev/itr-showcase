#pragma once

#include "CoreMinimal.h"
#include "EStance.generated.h"

UENUM(BlueprintType)
enum class EStance : uint8 {
    Standing = 0,
    Crouching = 1,
};
