#pragma once

#include "CoreMinimal.h"
#include "EGroundedEntryState.generated.h"

UENUM(BlueprintType)
enum class EGroundedEntryState : uint8 {
    None = 0,
    Roll = 1,
};
