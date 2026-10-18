#pragma once

#include "CoreMinimal.h"
#include "EDifficultyType.h"
#include "EItemsDropType.h"
#include "ETracersShowType.h"
#include "RadiusGameDifficulty.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FRadiusGameDifficulty {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool SleepRestoreHealth;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool LocationOnMap;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool ShowTips;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType Hunger;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType EnemySense;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType EnemyHealth;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType EnemyDamage;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType EnemyCount;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EItemsDropType ItemsDropType;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType ItemSellPrice;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType WeaponShotDamage;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType AnomalyDamage;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType AnomalyAmount;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    ETracersShowType ShowTracers;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType MissionMoneyReward;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EDifficultyType TideTime;
    FRadiusGameDifficulty();
};
