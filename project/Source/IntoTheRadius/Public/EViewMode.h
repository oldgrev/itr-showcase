#pragma once

#include "CoreMinimal.h"
#include "EViewMode.generated.h"

UENUM(BlueprintType)
enum class EViewMode : uint8 {
    ThirdPerson = 0,
    FirstPerson = 1,
};
