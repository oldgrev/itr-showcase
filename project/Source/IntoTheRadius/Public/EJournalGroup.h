#pragma once

#include "CoreMinimal.h"
#include "EJournalGroup.generated.h"

UENUM(BlueprintType)
enum class EJournalGroup : uint8 {
    Letters = 0,
    Pechorsk = 1,
    Tapes = 2,
    Tips = 3,
    Radius = 4,
    Enemies = 5,
    Anomalies = 6,
};
