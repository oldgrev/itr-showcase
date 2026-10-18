#pragma once

#include "CoreMinimal.h"
#include "EStartupType.generated.h"

UENUM(BlueprintType)
enum class EStartupType : uint8 {
    BuildShipping = 0,
    BuildDebug = 1,
    EditorNormal = 3,
    EditorCustom = 4,
};
