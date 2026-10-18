#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RadiusGameDifficulty.h"
#include "AnalyticsManager.generated.h"

class AActor;
class UMissionData;
class UPRGameInstance;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UAnalyticsManager : public UObject {
    GENERATED_BODY()
public:
    UAnalyticsManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnUnstuck(FVector Location);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnTutorialStart(const FGameplayTag TutorialId, const int32 TotalSteps);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnTutorialEnd(const FGameplayTag TutorialId, const int32 TotalSteps, const int32 CompletedSteps);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnTutorialControls();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnTransitionStart();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnTideHappening();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnSleep(const float Seconds, const bool isBlackout);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnSettingsGameplay(bool VirtualStock, bool PlayerHeight, bool NeckHeight, bool ArmLength, bool VignetteTurn, bool VignetteRun, bool HighlightDroppedItems, bool ShowBody, bool SeatedMode);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnSettingsControls(const bool bTurnType, const bool bTurnSpeed, const bool bMovementDirectionType, const bool bControllerRotation, const bool bHoldGrip, const bool bLeftHanded, const bool bMirrorHolsters, const bool bTeleportMovement);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnPlayerLocation(FVector Location, float AverageDelta);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnPlayerKill(AActor* KilledActor, const FGameplayTag weaponTag, const bool bIsSmoothing, const FVector DeathLocation);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnPlayerDeath(const FGameplayTag DeathCauser, const FVector DeathLocation);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnMoneyChanged(const int32 Value, const TArray<FString>& AnalyticsParams);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnMissionStateChanged(UMissionData* MissionData);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnMissionFinished(UMissionData* MissionData);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnMenuNewGame(const bool SkipTutor, const bool Ironman, const FRadiusGameDifficulty Difficulty);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnLogHmdDevice();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnLogFPS(const FString& Location, float Min, float Max, float Average);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnLevelStarted(const FGameplayTag Value);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnKatyasMonologue(FGameplayTag MonologueTag);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnJournalOpened(const FGameplayTag TabTag);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnGuitarPlayed(const int32 PlayCount, const float PlayTimeSeconds);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnGameStart();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnFinalChoice(const FString& Choice);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnDifficultyChanged();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void End();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void Begin(UPRGameInstance* GameInstance);

};
