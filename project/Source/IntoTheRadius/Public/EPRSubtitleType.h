#pragma once

#include "CoreMinimal.h"
#include "EPRSubtitleType.generated.h"

UENUM(BlueprintType)
enum class EPRSubtitleType : uint8 {
    Record = 0,
    Player = 1,
    Katya = 2,
    Presence = 3,
    Unknown = 50,
};
