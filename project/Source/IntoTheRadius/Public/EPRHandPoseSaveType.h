#pragma once

#include "CoreMinimal.h"
#include "EPRHandPoseSaveType.generated.h"

UENUM(BlueprintType)
enum class EPRHandPoseSaveType : uint8 {
    Tag = 0,
    StaticMeshComponentPath = 1,
};
