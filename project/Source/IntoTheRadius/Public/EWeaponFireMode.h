#pragma once

#include "CoreMinimal.h"
#include "EWeaponFireMode.generated.h"

UENUM(BlueprintType)
enum class EWeaponFireMode : uint8 {
    Safety = 0,
    Single = 1,
    FullAuto = 2,
    Burst3 = 3,
};
