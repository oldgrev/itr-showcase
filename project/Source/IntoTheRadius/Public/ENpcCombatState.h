#pragma once

#include "CoreMinimal.h"
#include "ENpcCombatState.generated.h"

UENUM(BlueprintType)
enum class ENpcCombatState : uint8 {
    Uninitialized = 0,
    InCombat = 1,
    WaitingForCombat = 2,
};
