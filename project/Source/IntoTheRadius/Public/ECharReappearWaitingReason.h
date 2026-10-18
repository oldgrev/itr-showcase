#pragma once

#include "CoreMinimal.h"
#include "ECharReappearWaitingReason.generated.h"

UENUM(BlueprintType)
enum class ECharReappearWaitingReason : uint8 {
    None = 0,
    WaitForReappearDelay = 1,
    WaitForCoverSearch = 2,
    WaitToLeaveView = 3,
};
