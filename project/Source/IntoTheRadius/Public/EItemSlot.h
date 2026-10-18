#pragma once

#include "CoreMinimal.h"
#include "EItemSlot.generated.h"

UENUM(BlueprintType)
enum class EItemSlot : uint8 {
    None = 0,
    Magazine = 1,
    Barrel = 2,
    Stock = 3,
    Rail_01 = 11,
    Rail_02 = 12,
    Rail_03 = 13,
    Rail_04 = 14,
    Slot_01 = 21,
    Slot_02 = 22,
    Slot_03 = 23,
    Slot_04 = 24,
};
