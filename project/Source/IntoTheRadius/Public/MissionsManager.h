#pragma once

#include "CoreMinimal.h"
#include "Engine/LatentActionManager.h"
#include "GameplayTagContainer.h"
#include "EMissionState.h"
#include "IClearable.h"
#include "IPreparable.h"
#include "MissionsManager.generated.h"

class UMissionData;
class UMissionsManager;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionsManager : public UObject, public IIClearable, public IIPreparable {
    GENERATED_BODY()
public:
    UMissionsManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartMissionFromIdLatent(bool& bSuccess, FGameplayTag GameplayTag, UObject* WorldContextObject, FLatentActionInfo LatentInfo);

    UFUNCTION(BlueprintCallable)
    void StartMission(const FString& MissionInstanceId, bool& bSuccess, UMissionData*& MissionData);

    UFUNCTION(BlueprintCallable)
    void SetSelectedMissionComplete(const FString MissionInstanceId);

    UFUNCTION(BlueprintCallable)
    void ResetTutorialMissions();

private:
    UFUNCTION()
    void OnPlayerLevelChanged(const int32 PlayerLevel);

public:
    UFUNCTION(BlueprintPure)
    void IsMissionSelected(const FString MissionInstanceId, bool& bMissionSelected);

    UFUNCTION(BlueprintPure)
    bool IsMaxExecutingReached();

    UFUNCTION(BlueprintCallable)
    bool GetStoryMissionUnlockInfo(int32& FinishedAfterPrevStory, int32& RequiredAfterPrevStory);

    UFUNCTION(BlueprintPure)
    void GetSelectedMissionsInState(const EMissionState State, TArray<UMissionData*>& SelectedMissions);

    UFUNCTION(BlueprintPure)
    TArray<UMissionData*> GetSelectedMissionsInProgress();

    UFUNCTION(BlueprintPure)
    void GetSelectedMissions(TArray<UMissionData*>& SelectedMissions);

    UFUNCTION(BlueprintPure)
    static UMissionsManager* GetMissionsManager();

    UFUNCTION(BlueprintCallable)
    int32 GetMissionsFinishedAfter(const FGameplayTag ConfigID, const bool bOnlySuccessful);

    UFUNCTION(BlueprintCallable)
    void GetMission(const FString& MissionInstanceId, UMissionData*& MissionData);

    UFUNCTION(BlueprintPure)
    void GetFinishedMissions(TArray<UMissionData*>& FinishedMissions);

    UFUNCTION(BlueprintCallable)
    bool GetAvailableStoryMission(UMissionData*& StoryMission);

    UFUNCTION(BlueprintPure)
    void GetActiveMissions(TMap<FGameplayTag, UMissionData*>& ActiveMissions);

    UFUNCTION(BlueprintPure)
    void GetActiveMissionOfType(const FGameplayTag& Category, UMissionData*& MissionData);

    UFUNCTION(BlueprintCallable)
    bool GenerateNewMissions(bool bTide);

    UFUNCTION(BlueprintCallable)
    bool FinishMission(const FString MissionInstanceId);

    UFUNCTION(BlueprintCallable)
    void CheckActive();

    UFUNCTION(BlueprintCallable)
    void AbortSelectedMission(const FString MissionInstanceId);

};
