#pragma once

#include "CoreMinimal.h"
#include "EFootStepType.generated.h"

UENUM(BlueprintType)
enum class EFootStepType : uint8 {
    Step = 0,
    WalkOrRun = 1,
    Jump = 2,
    Land = 3,
};
