#pragma once

#include "CoreMinimal.h"
#include "EBodyArmorSetupTypes.generated.h"

UENUM(BlueprintType)
enum class EBodyArmorSetupTypes : uint8 {
    AddNewMesh = 0,
    SwitchBodyMesh = 1,
    SwitchBodyMaterials = 2,
};
