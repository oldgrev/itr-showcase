#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ShootingScores.h"
#include "PRCommonGameData.generated.h"

class UInventoryItem;
class UMissionData;
class UPRCommonGameData;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRCommonGameData : public UObject {
    GENERATED_BODY()
public:
    UPRCommonGameData(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTrigger(const FGameplayTag Tag);

    UFUNCTION(BlueprintCallable)
    void SaveShootingRun(const float RunTime, const int32 Scores, const int32 Hits, const int32 Misses, const int32 GrenadeKills);

private:
    UFUNCTION()
    void OnMissionChange(UMissionData* MissionData);

    UFUNCTION()
    void OnItemTaken(UInventoryItem* Item);

public:
    UFUNCTION(BlueprintPure)
    bool IsWeaponUnlocked(const FGameplayTag Tag);

    UFUNCTION(BlueprintCallable)
    void Initialize();

    UFUNCTION(BlueprintPure)
    int32 IncrementGuitarPlayCount();

    UFUNCTION(BlueprintPure)
    bool GetTrigger(const FGameplayTag Tag);

    UFUNCTION(BlueprintPure)
    float GetTotalPlaytimeMinutes();

    UFUNCTION(BlueprintPure)
    static void GetCommonGameData(UPRCommonGameData*& Data);

    UPROPERTY(BlueprintReadWrite)
    FDateTime SaveDateTime;
    UPROPERTY(BlueprintReadWrite)
    TArray<FShootingScores> ShootingScoreboard;
    UPROPERTY(BlueprintReadWrite)
    FShootingScores LastShootingScores;
    UPROPERTY(BlueprintReadWrite)
    FGameplayTagContainer ObtainedWeapons;
    UPROPERTY(BlueprintReadOnly)
    FGameplayTagContainer FinishedMissions;
    UPROPERTY(BlueprintReadOnly)
    int32 FinishedMissionsCount;
    UPROPERTY(BlueprintReadWrite)
    TArray<FGameplayTag> CommonTriggers;
    UPROPERTY(BlueprintReadOnly)
    FString FirstSessionDateString;
    UPROPERTY(BlueprintReadOnly)
    int32 MaxPlayerLevel;
    UPROPERTY()
    int64 GameTotalTicks;
    UPROPERTY(BlueprintReadOnly)
    int32 SessionCount;
    UPROPERTY(BlueprintReadOnly)
    int32 GuitarPlayCount;
    UPROPERTY()
    bool bCachedHasSupporterPack;
};
