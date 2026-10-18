#pragma once

#include "CoreMinimal.h"
#include "EMissionType.generated.h"

UENUM(BlueprintType)
enum class EMissionType : uint8 {
    Tutorial = 0,
    Story = 1,
    Generic = 2,
    SpecialArtifacts = 3,
    SpecialGenerators = 4,
};
