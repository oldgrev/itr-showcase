#pragma once

#include "CoreMinimal.h"
#include "ECharCommand.generated.h"

UENUM(BlueprintType)
enum class ECharCommand : uint8 {
    Idle = 0,
    Walk = 1,
    Attack = 2,
};
