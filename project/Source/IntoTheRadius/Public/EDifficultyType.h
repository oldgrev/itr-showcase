#pragma once

#include "CoreMinimal.h"
#include "EDifficultyType.generated.h"

UENUM(BlueprintType)
enum class EDifficultyType : uint8 {
    None = 0,
    HighlyDecreased = 10,
    Decreased = 20,
    Normal = 30,
    Increased = 40,
    HighlyIncreased = 50,
};
