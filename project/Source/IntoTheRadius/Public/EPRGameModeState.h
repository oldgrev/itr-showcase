#pragma once

#include "CoreMinimal.h"
#include "EPRGameModeState.generated.h"

UENUM(BlueprintType)
enum class EPRGameModeState : uint8 {
    Init = 0,
    Ready = 1,
    TransitionUnloading = 10,
    TransitionLoading = 11,
    TransitionWaitingForPSO = 12,
    TransitionPreparing = 13,
    TransitionStarting = 14,
};
