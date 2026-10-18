#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DebugEventDelegate.h"
#include "IClearable.h"
#include "NoParamsDelegate.h"
#include "OneParamActorDelegate.h"
#include "OneParamBoolDelegate.h"
#include "OneParamEnvironmentDelegate.h"
#include "OneParamFloatDelegate.h"
#include "OneParamIntDelegate.h"
#include "OneParamItemDelegate.h"
#include "OneParamItemsArrayDelegate.h"
#include "OneParamMissionDelegate.h"
#include "OneParamTagDelegate.h"
#include "ThreeParamsGTagIntAndStringsArrayDelegate.h"
#include "ThreeParamsGameSaveDelegate.h"
#include "TwoParamsActorGTagDelegate.h"
#include "TwoParamsGTagsDelegate.h"
#include "TwoParamsIntAndStringArrayDelegate.h"
#include "TwoParamsMissionAndObjectiveDelegate.h"
#include "TwoParamsSleepDelegate.h"
#include "EventsManager.generated.h"

class AActor;
class APREnvironment;
class UEventsManager;
class UInventoryItem;
class UMissionAbstractObjectiveData;
class UMissionData;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UEventsManager : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UEventsManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static UEventsManager* GetEventsManager();

    UFUNCTION(BlueprintCallable)
    void FireOnWildSpawnerCleared(AActor* SpawnerActor);

    UFUNCTION()
    void FireOnVirtualStockChanged();

    UFUNCTION(BlueprintCallable)
    void FireOnTutorialStarted(FGameplayTag TutorialId);

    UFUNCTION(BlueprintCallable)
    void FireOnTutorialSequenceFinished(AActor* SequenceActor);

    UFUNCTION(BlueprintCallable)
    void FireOnTriggerUnset(FGameplayTag Trigger);

    UFUNCTION(BlueprintCallable)
    void FireOnTriggerPassed(FGameplayTag Trigger);

    UFUNCTION(BlueprintCallable)
    void FireOnTransitionStart();

    UFUNCTION(BlueprintCallable)
    void FireOnTransitionEnd();

    UFUNCTION(BlueprintCallable)
    void FireOnTideHappening();

    UFUNCTION(BlueprintCallable)
    void FireOnSwitchAiCoverDebug();

    UFUNCTION(BlueprintCallable)
    void FireOnStoryNotePassed(FGameplayTag NoteID);

    UFUNCTION(BlueprintCallable)
    void FireOnStashOpened(AActor* StashActor);

    UFUNCTION()
    void FireOnShowBodyChanged();

    UFUNCTION(BlueprintCallable)
    void FireOnShotFired();

    UFUNCTION(BlueprintCallable)
    void FireOnReferencesClearing();

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerWalking();

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerTurning();

    UFUNCTION()
    void FireOnPlayerStarted();

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerSleep(const float Seconds, const bool bIsBlackout);

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerRunning();

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerReset();

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerMoneyChanged(const int32 Value, const TArray<FString>& AnalyticsParams);

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerLevelChanged(const int32 PlayerLevel);

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerKilledNPC(AActor* NPCActor, FGameplayTag weaponTag);

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerEyesOpen(bool bIsOpen);

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerDied();

    UFUNCTION(BlueprintCallable)
    void FireOnPlayerBodyVisibilityChanged(const bool bValue);

    UFUNCTION(BlueprintCallable)
    void FireOnPictureTaken(AActor* Actor);

    UFUNCTION(BlueprintCallable)
    void FireOnObjectiveRestored(UMissionData* MissionData, UMissionAbstractObjectiveData* objectiveData);

    UFUNCTION(BlueprintCallable)
    void FireOnObjectiveProgress(UMissionData* MissionData, UMissionAbstractObjectiveData* objectiveData);

    UFUNCTION(BlueprintCallable)
    void FireOnObjectiveFinished(UMissionData* MissionData, UMissionAbstractObjectiveData* objectiveData);

    UFUNCTION(BlueprintCallable)
    void FireOnNPCDied(AActor* NPCActor);

    UFUNCTION(BlueprintCallable)
    void FireOnNewMissionAdded(UMissionData* MissionData);

    UFUNCTION(BlueprintCallable)
    void FireOnNewJournalNote(FGameplayTag NoteID);

    UFUNCTION(BlueprintCallable)
    void FireOnMissionStateChanged(UMissionData* MissionData);

    UFUNCTION(BlueprintCallable)
    void FireOnMissionPreview(UMissionData* MissionData);

    UFUNCTION(BlueprintCallable)
    void FireOnMissionFinished(UMissionData* MissionData);

    UFUNCTION(BlueprintCallable)
    void FireOnLevelStarted(FGameplayTag LevelTag);

    UFUNCTION(BlueprintCallable)
    void FireOnLevelPrepare(FGameplayTag LevelTag);

    UFUNCTION(BlueprintCallable)
    void FireOnLanguageChanged();

    UFUNCTION(BlueprintCallable)
    void FireOnItemUpdated(const FGameplayTag ItemTag, const FGameplayTag UpgradeID);

    UFUNCTION(BlueprintCallable)
    void FireOnItemTaken(UInventoryItem* InventoryItem);

    UFUNCTION(BlueprintCallable)
    void FireOnItemStored(UInventoryItem* InventoryItem);

    UFUNCTION(BlueprintCallable)
    void FireOnItemsSold(TArray<UInventoryItem*> Items);

    UFUNCTION(BlueprintCallable)
    void FireOnItemRemoved(UInventoryItem* InventoryItem);

    UFUNCTION(BlueprintCallable)
    void FireOnItemDropped(AActor* itemActor);

    UFUNCTION(BlueprintCallable)
    void FireOnItemChangeDurability(UInventoryItem* InventoryItem);

    UFUNCTION(BlueprintCallable)
    void FireOnItemBought(UInventoryItem* InventoryItem);

    UFUNCTION(BlueprintCallable)
    void FireOnItemActorRefRemoved(UInventoryItem* InventoryItem);

    UFUNCTION(BlueprintCallable)
    void FireOnInventoryModeChanged();

    UFUNCTION(BlueprintCallable)
    void FireOnHolderFixed(const FGameplayTag HolderID, const int32 TotalItems, const TArray<FString>& FixedItems);

    UFUNCTION(BlueprintCallable)
    void FireOnGameTimeChanged(float DeltaSeconds);

    UFUNCTION()
    void FireOnGameStarted();

    UFUNCTION(BlueprintCallable)
    void FireOnGameShutdown();

    UFUNCTION(BlueprintCallable)
    void FireOnGameplayTimeDilationChanged(float TimeDilation);

    UFUNCTION(BlueprintCallable)
    void FireOnGamePaused(const bool bIsPaused);

    UFUNCTION()
    void FireOnGameModeStarted();

    UFUNCTION()
    void FireOnGameInstanceStarted();

    UFUNCTION(BlueprintCallable)
    void FireOnGameDataSaved(const int32 SlotNr, const int32 SaveNr, const float SizeMb);

    UFUNCTION(BlueprintCallable)
    void FireOnGameDataSave();

    UFUNCTION(BlueprintCallable)
    void FireOnFirstTimeTaken(const FGameplayTag ItemTag);

    UFUNCTION(BlueprintCallable)
    void FireOnEnvironmentRePrepared(const APREnvironment* Environment);

    UFUNCTION()
    void FireOnDifficultyChanged();

    UFUNCTION(BlueprintCallable)
    void FireOnCustomMapMarkPassed(FGameplayTag MarkID);

    UFUNCTION(BlueprintCallable)
    void FireOnConsumableUsing(UInventoryItem* Item);

    UFUNCTION(BlueprintCallable)
    void FireOnConsumableActorUsing(AActor* itemActor);

    UPROPERTY()
    FNoParamsDelegate OnGameInstanceStarted;
    UPROPERTY()
    FNoParamsDelegate OnGameModeStarted;
    UPROPERTY()
    FNoParamsDelegate OnPlayerStarted;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnGameStarted;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnGameShutdown;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnGameDataSave;
    UPROPERTY(BlueprintAssignable)
    FThreeParamsGameSave OnGameDataSaveDone;
    UPROPERTY(BlueprintAssignable)
    FOneParamFloatDelegate OnGameTimeChanged;
    UPROPERTY(BlueprintAssignable)
    FOneParamFloatDelegate OnGameplayTimeDilationChanged;
    UPROPERTY(BlueprintAssignable)
    FOneParamBool OnGamePaused;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnReferencesClearing;
    UPROPERTY(BlueprintAssignable)
    FOneParamEnvironment OnEnvironmentRePrepared;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnTransitionStart;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnTransitionStartOnce;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnTransitionEnd;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnTransitionEndOnce;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnLevelPrepare;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnLevelPrepareOnce;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnLevelStarted;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnLevelStartedOnce;
    UPROPERTY(BlueprintAssignable)
    FOneParamActor OnItemDropped;
    UPROPERTY(BlueprintAssignable)
    FOneParamItem OnItemTaken;
    UPROPERTY(BlueprintAssignable)
    FOneParamItem OnItemStored;
    UPROPERTY(BlueprintAssignable)
    FOneParamItemsArray OnItemsSold;
    UPROPERTY(BlueprintAssignable)
    FOneParamItem OnItemBought;
    UPROPERTY(BlueprintAssignable)
    FTwoParamsIntAndStringArray OnPlayerMoneyChanged;
    UPROPERTY(BlueprintAssignable)
    FOneParamItem OnItemChangeDurability;
    UPROPERTY(BlueprintAssignable)
    FOneParamInt OnPlayerLevelChanged;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnInventoryModeChanged;
    UPROPERTY(BlueprintAssignable)
    FOneParamItem OnItemRemoved;
    UPROPERTY(BlueprintAssignable)
    FOneParamItem OnItemActorRefRemoved;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnFirstTimeTaken;
    UPROPERTY(BlueprintAssignable)
    FTwoParamsGTagsDelegate OnItemUpdated;
    UPROPERTY(BlueprintAssignable)
    FThreeParamsGTagIntAndStringsArray OnHolderFixed;
    UPROPERTY(BlueprintAssignable)
    FOneParamMission OnNewMissionAdded;
    UPROPERTY(BlueprintAssignable)
    FOneParamMission OnMissionPreview;
    UPROPERTY(BlueprintAssignable)
    FOneParamMission OnMissionFinished;
    UPROPERTY(BlueprintAssignable)
    FOneParamMission OnMissionStateChanged;
    UPROPERTY(BlueprintAssignable)
    FTwoParamsMissionAndObjective OnObjectiveFinished;
    UPROPERTY(BlueprintAssignable)
    FTwoParamsMissionAndObjective OnObjectiveRestored;
    UPROPERTY(BlueprintAssignable)
    FTwoParamsMissionAndObjective OnObjectiveProgress;
    UPROPERTY(BlueprintAssignable)
    FOneParamActor OnTutorialSequenceFinished;
    UPROPERTY(BlueprintAssignable)
    FTwoParamsActorGTag OnPlayerKilledNPC;
    UPROPERTY(BlueprintAssignable)
    FOneParamActor OnNPCDied;
    UPROPERTY(BlueprintAssignable)
    FOneParamActor OnWildSpawnerCleared;
    UPROPERTY(BlueprintAssignable)
    FOneParamActor OnPictureTaken;
    UPROPERTY(BlueprintAssignable)
    FOneParamActor OnStashOpened;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnTriggerPassed;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnTriggerUnset;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnStoryNotePassed;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnCustomMapMarkPassed;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnNewJournalNote;
    UPROPERTY(BlueprintAssignable)
    FOneParamItem OnConsumableUsing;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnShotFired;
    UPROPERTY(BlueprintAssignable)
    FOneParamTag OnTutorialStarted;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnTideHappening;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnDifficultyChanged;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnVirtualStockChanged;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnShowBodyChanged;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnLanguageChanged;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnPlayerReset;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnPlayerDied;
    UPROPERTY(BlueprintAssignable)
    FOneParamBool OnPlayerEyesOpen;
    UPROPERTY(BlueprintAssignable)
    FTwoParamsSleep OnPlayerSleep;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnPlayerTurning;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnPlayerWalking;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnPlayerRunning;
    UPROPERTY(BlueprintAssignable)
    FOneParamBool OnPlayerBodyVisibilityChanged;
    UPROPERTY(BlueprintAssignable)
    FDebugEvent OnSwitchAiCoverDebug;
};
