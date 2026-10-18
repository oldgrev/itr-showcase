#pragma once

#include "CoreMinimal.h"
#include "EWeaponInfoParameter.generated.h"

UENUM(BlueprintType)
enum class EWeaponInfoParameter : uint8 {
    Damage = 0,
    Recoil = 1,
    Accuracy = 2,
    FireRate = 3,
    Reliability = 4,
};
