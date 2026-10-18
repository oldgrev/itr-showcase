#pragma once

#include "CoreMinimal.h"
#include "ETracersShowType.generated.h"

UENUM(BlueprintType)
enum class ETracersShowType : uint8 {
    None = 0,
    Enemies = 1,
    Player = 2,
    All = 3,
};
