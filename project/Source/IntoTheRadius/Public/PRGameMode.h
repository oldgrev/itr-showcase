#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameplayTagContainer.h"
#include "DebugAndCheats.h"
#include "EPRGameModeState.h"
#include "IPRGameMode.h"
#include "IPRGameModeNative.h"
#include "ReadyMarkInterface.h"
#include "PRGameMode.generated.h"

class AActor;
class APREnvironment;
class APRGameMode;
class APawn;
class UMissionData;

UCLASS(Blueprintable, BlueprintType, Config=Game)
class INTOTHERADIUS_API APRGameMode : public AGameModeBase, public IIPRGameMode, public IIPRGameModeNative, public IReadyMarkInterface, public IDebugAndCheats {
    GENERATED_BODY()
public:
    APRGameMode(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(Exec)
    void TogglePause();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void TickDebug();

public:
    UFUNCTION(BlueprintCallable)
    void SetGameplayTimeDilation(const float Dilation);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void RestorePlayerIfDead();

private:
    UFUNCTION(BlueprintCallable)
    void ResetAutosaveTimer_Native();

    UFUNCTION()
    void RecallLevelLoaded();

public:
    UFUNCTION(BlueprintCallable)
    void PreparePlayerForFinalChoice();

protected:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void PrepareMissionExecutor();

    UFUNCTION(BlueprintImplementableEvent)
    void OnTransitionStart();

    UFUNCTION(BlueprintImplementableEvent)
    void OnTransitionHint();

    UFUNCTION(BlueprintImplementableEvent)
    void OnTransitionEnd();

    UFUNCTION(BlueprintImplementableEvent)
    void OnTideHappening(bool bReload);

    UFUNCTION(BlueprintImplementableEvent)
    void OnStartedGame();

    UFUNCTION(BlueprintImplementableEvent)
    void OnStartedEditor();

    UFUNCTION(BlueprintImplementableEvent)
    void OnMissionStateChanged(UMissionData* MissionData);

private:
    UFUNCTION()
    void OnLevelUnloaded();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnLevelStarted(FGameplayTag LevelTag);

    UFUNCTION(BlueprintImplementableEvent)
    void OnLevelPrepare(FGameplayTag LevelTag);

private:
    UFUNCTION()
    void OnLevelLoaded();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnInitializeGame();

    UFUNCTION(BlueprintImplementableEvent)
    void OnInitializeEditor();

private:
    UFUNCTION()
    void OnGameStarted();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnGameDataPreSave();

    UFUNCTION(BlueprintImplementableEvent)
    void OnEnteredMenu();

    UFUNCTION(BlueprintCallable)
    void OnEditorLevelLoaded();

public:
    UFUNCTION(BlueprintPure)
    static FString MakeActorUID(AActor* Actor);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void KillActorsOnReload();

    UFUNCTION(BlueprintPure)
    static void GetPRGameMode(APRGameMode*& GameMode);

    UFUNCTION(BlueprintCallable)
    void GetGameplayTimeDilation(float& Dilation) const;

    UFUNCTION(BlueprintPure)
    APREnvironment* GetCurrentEnvironment();

    UFUNCTION(BlueprintPure)
    static FString GetActorUID(AActor* Actor);

private:
    UFUNCTION()
    void FinishTransfer();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void FindLevelStart(const FGameplayTag LevelTag, const FGameplayTag LocationTag, FTransform& Transform, FVector& Velocity, bool& bFromSave);

private:
    UFUNCTION()
    void DoTransferToLevel();

    UFUNCTION()
    void DoStart();

    UFUNCTION()
    void DoPrepare();

    UFUNCTION()
    void DoEndTransition();

protected:
    UFUNCTION(BlueprintCallable)
    void ContinueTransitionLoad();

private:
    UFUNCTION()
    void BeginWaitingForPSO();

public:
    UPROPERTY(BlueprintReadOnly)
    EPRGameModeState State;
    UPROPERTY(BlueprintReadWrite)
    FTransform TransitionStartTransform;
protected:
    UPROPERTY(BlueprintReadWrite)
    bool bRespawnInventory;
private:
    UPROPERTY()
    APawn* RadiusPlayerPawn;
    UPROPERTY()
    bool bSleepAllowed;
    UPROPERTY()
    bool bForcePause;
public:
    UPROPERTY(BlueprintReadWrite)
    bool Autosave;
};
