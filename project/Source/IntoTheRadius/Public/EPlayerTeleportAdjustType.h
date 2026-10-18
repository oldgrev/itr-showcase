#pragma once

#include "CoreMinimal.h"
#include "EPlayerTeleportAdjustType.generated.h"

UENUM(BlueprintType)
enum class EPlayerTeleportAdjustType : uint8 {
    None = 0,
    Location = 1,
    LocationAndRotation = 2,
};
