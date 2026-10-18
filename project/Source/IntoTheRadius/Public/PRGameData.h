#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EJournalGroup.h"
#include "EPRGameDifficultyPreset.h"
#include "GameDifficulty.h"
#include "IClearable.h"
#include "IPreparable.h"
#include "LevelDecorData.h"
#include "MapData.h"
#include "NoteData.h"
#include "PlayerStats.h"
#include "RadiusGameDifficulty.h"
#include "PRGameData.generated.h"

class UGameInventory;
class UGameMissions;
class UInventoryItem;
class UMissionAbstractObjectiveData;
class UMissionData;
class UPRGameData;
class UPlayerGameData;
class USpawnerGameData;
class UTextureRenderTarget2D;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRGameData : public UObject, public IIClearable, public IIPreparable {
    GENERATED_BODY()
public:
    UPRGameData(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateMarker(const FString Marker, const bool bRemove);

    UFUNCTION(BlueprintCallable)
    bool UnsetTrigger(const FGameplayTag& Trigger);

    UFUNCTION(BlueprintCallable)
    bool StatAddUniqueItem(const FGameplayTag ItemId);

    UFUNCTION(BlueprintCallable)
    void StatAddKill(const FGameplayTag NPCTag, const FGameplayTag weaponTag);

    UFUNCTION(BlueprintCallable)
    void StatAddDeath(const FGameplayTag KillerTag);

    UFUNCTION(BlueprintCallable)
    bool SetTrigger(const FGameplayTag& Trigger);

    UFUNCTION(BlueprintCallable)
    void SetPlayerLevel(const int32 PlayerLevel);

    UFUNCTION(BlueprintCallable)
    void SaveSleepLocation(const FGameplayTag Level, const FVector Location);

    UFUNCTION(BlueprintCallable)
    void SaveDecorItemTransform(const FString DecorId, const FTransform Transform);

    UFUNCTION(BlueprintCallable)
    void SaveDecorItemDestroyed(const FString DecorId);

    UFUNCTION(BlueprintCallable)
    void SaveDeathLocation(const FGameplayTag Level, const FVector Location);

    UFUNCTION(BlueprintCallable)
    void ResetGameData();

    UFUNCTION(BlueprintCallable)
    void RemoveSleepLocation(const FGameplayTag Level);

    UFUNCTION(BlueprintCallable)
    void RemoveDeathLocation(const FGameplayTag Level);

    UFUNCTION(BlueprintCallable)
    void PrintMissions(const FString& Message);

    UFUNCTION(BlueprintCallable)
    void PrintInventory(const FString& Message);

    UFUNCTION(BlueprintCallable)
    void PrintData(const FString& Message);

    UFUNCTION(BlueprintCallable)
    void PrepareNewGame(const FRadiusGameDifficulty NewDifficulty, const bool bIronman, const bool bSkipTutorial, const bool bStartupConfig, const TArray<FGameplayTag> Triggers);

private:
    UFUNCTION()
    void OnPlayerLevelChanged(int32 PlayerLevel);

    UFUNCTION()
    void OnObjectiveChange(UMissionData* MissionData, UMissionAbstractObjectiveData* Objective);

    UFUNCTION()
    void OnMissionChange(UMissionData* MissionData);

    UFUNCTION()
    void OnItemTaken(UInventoryItem* Item);

    UFUNCTION()
    void OnItemStored(UInventoryItem* Item);

public:
    UFUNCTION(BlueprintCallable)
    bool IsManOfHisWord() const;

    UFUNCTION(BlueprintPure)
    bool IsKatyaMonologueInvalid(const FGameplayTag& Tag, const bool bIgnoreConditions);

    UFUNCTION(BlueprintCallable)
    bool IsJournalGroupHasNewNotes(EJournalGroup Group) const;

    UFUNCTION(BlueprintCallable)
    bool HasMoney(const int32 Amount) const;

    UFUNCTION(BlueprintPure)
    FString GetUID();

    UFUNCTION(BlueprintPure)
    static void GetSpawnSaveData(USpawnerGameData*& SpawnSaveData);

    UFUNCTION(BlueprintCallable)
    bool GetSleepLocation(const FGameplayTag Level, FVector& Location) const;

    UFUNCTION(BlueprintCallable)
    float GetSecondsPassed() const;

    UFUNCTION(BlueprintCallable)
    float GetSecondsLastTide() const;

    UFUNCTION(BlueprintPure)
    float GetRealSecondsToTide();

    UFUNCTION(BlueprintCallable)
    float GetPlaytimeSeconds() const;

    UFUNCTION(BlueprintCallable)
    float GetPlaytimeMinutes() const;

    UFUNCTION(BlueprintCallable)
    int32 GetPlayerLevel() const;

    UFUNCTION(BlueprintCallable)
    void GetMapRenderTarget(const FGameplayTag LevelTag, UTextureRenderTarget2D*& RenderTarget);

    UFUNCTION(BlueprintCallable)
    TArray<FNoteData> GetJournalGroupNotes(EJournalGroup Group);

    UFUNCTION(BlueprintPure)
    float GetGameSecondsToTide();

    UFUNCTION(BlueprintPure)
    static void GetGameData(UPRGameData*& GameData);

    UFUNCTION(BlueprintCallable)
    EPRGameDifficultyPreset GetDifficultyPreset() const;

    UFUNCTION(BlueprintCallable)
    void GetDecorItemTransform(const FString DecorId, FTransform& Transform, bool& bDestroyed, bool& bSuccess);

    UFUNCTION(BlueprintCallable)
    bool GetDeathLocation(const FGameplayTag Level, FVector& Location) const;

    UFUNCTION(BlueprintCallable)
    void FillFrom(UPRGameData* Other);

    UFUNCTION(BlueprintCallable)
    void DumpData(const FString& Message);

    UFUNCTION(BlueprintPure)
    bool CheckTrigger(const FGameplayTag& Trigger);

    UFUNCTION(BlueprintCallable)
    void CheckTideTriggers();

    UFUNCTION(BlueprintPure)
    bool CheckMarker(const FString Marker);

    UFUNCTION(BlueprintCallable)
    void CheckGameTriggers();

    UFUNCTION(BlueprintCallable)
    void ChangeMoney(const int32 ChangeBy, const TArray<FString>& AnalyticsParams);

    UFUNCTION(BlueprintCallable)
    bool ChangeGameDifficulty(const FRadiusGameDifficulty Value);

    UFUNCTION(BlueprintCallable)
    void ApplyTideReset();

private:
    UPROPERTY()
    UPlayerGameData* BackupPlayerData;
public:
    UPROPERTY(BlueprintReadOnly)
    UPlayerGameData* PlayerData;
    UPROPERTY(BlueprintReadOnly)
    UGameMissions* MissionsData;
    UPROPERTY(BlueprintReadOnly)
    UGameInventory* InventoryData;
    UPROPERTY(BlueprintReadOnly)
    USpawnerGameData* SpawnSaveData;
    UPROPERTY()
    uint64 UID;
    UPROPERTY(BlueprintReadOnly)
    int32 SlotNr;
    UPROPERTY(BlueprintReadOnly)
    FDateTime SaveDateDime;
    UPROPERTY(BlueprintReadOnly)
    FString SaveMessage;
    UPROPERTY(BlueprintReadOnly)
    FPlayerStats PlayerStats;
    UPROPERTY(BlueprintReadOnly)
    TArray<FGameplayTag> VisitedLevels;
    UPROPERTY()
    FDateTime TimeStart;
    UPROPERTY()
    int64 TicksPassed;
    UPROPERTY()
    int64 LastTideTicks;
    UPROPERTY()
    EPRGameDifficultyPreset Difficulty;
    UPROPERTY()
    FGameDifficulty GameDifficulty;
    UPROPERTY(BlueprintReadOnly)
    FRadiusGameDifficulty GameDifficultyConfig;
    UPROPERTY(BlueprintReadOnly)
    bool Ironman;
    UPROPERTY()
    bool IntactDifficulty;
    UPROPERTY(BlueprintReadOnly)
    FString GameUID;
    UPROPERTY(BlueprintReadOnly)
    FString GameStartDateString;
    UPROPERTY()
    int64 GameRealTicks;
    UPROPERTY()
    TMap<FGameplayTag, FMapData> MapsData;
    UPROPERTY()
    TMap<FGameplayTag, FLevelDecorData> LevelDecorItems;
    UPROPERTY(BlueprintReadOnly)
    FGameplayTag PreviousLevelTag;
    UPROPERTY(BlueprintReadOnly)
    FGameplayTag CurrentLevelTag;
    UPROPERTY(BlueprintReadOnly)
    FGameplayTag NextLevelTag;
    UPROPERTY(BlueprintReadOnly)
    TArray<FGameplayTag> PassedTriggers;
    UPROPERTY(BlueprintReadOnly)
    TArray<FString> CustomMarkers;
};
