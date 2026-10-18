#pragma once

#include "CoreMinimal.h"
#include "EMissionState.generated.h"

UENUM(BlueprintType)
enum class EMissionState : uint8 {
    Ready = 0,
    Briefing = 1,
    Debriefing = 2,
    Executing = 10,
    Successful = 20,
    Failed = 21,
    Rejected = 22,
    Missed = 23,
};
