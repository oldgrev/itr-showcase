#pragma once

#include "CoreMinimal.h"
#include "ELevelManagerState.generated.h"

UENUM(BlueprintType)
enum class ELevelManagerState : uint8 {
    Ready = 0,
    Loading = 1,
    Unloading = 3,
};
