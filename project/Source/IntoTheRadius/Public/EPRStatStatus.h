#pragma once

#include "CoreMinimal.h"
#include "EPRStatStatus.generated.h"

UENUM(BlueprintType)
enum class EPRStatStatus : uint8 {
    End = 0,
    Low = 1,
    Normal = 2,
};
