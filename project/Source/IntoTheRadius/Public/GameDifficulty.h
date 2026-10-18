#pragma once

#include "CoreMinimal.h"
#include "EEnemySenseType.h"
#include "EItemsDropType.h"
#include "GameDifficulty.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FGameDifficulty {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool SleepRestoreHealth;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool LocationOnMap;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EEnemySenseType EnemySense;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool ShowTracers;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool ShowTips;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EItemsDropType ItemsDropType;
    FGameDifficulty();
};
