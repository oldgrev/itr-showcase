#pragma once

#include "CoreMinimal.h"
#include "ENpcPointQueryType.generated.h"

UENUM(BlueprintType)
enum class ENpcPointQueryType : uint8 {
    None = 0,
    Cover = 1,
    Shooting = 2,
    Assault = 3,
};
