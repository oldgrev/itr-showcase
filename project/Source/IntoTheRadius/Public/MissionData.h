#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EMissionState.h"
#include "IClearable.h"
#include "TagToTagsList.h"
#include "MissionData.generated.h"

class AActor;
class UMissionAbstractObjectiveData;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionData : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UMissionData(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTutorStep(FGameplayTag SequencerID, int32 step);

    UFUNCTION(BlueprintPure)
    bool HaveDelivery();

    UFUNCTION(BlueprintCallable)
    void GetTotalReward(const bool FinishedOnly, int32& MoneyReward, int32& PlayerLevel);

    UFUNCTION(BlueprintPure)
    float GetTimeTillAbortAvailable();

    UFUNCTION(BlueprintCallable)
    FString GetStashUID(UMissionAbstractObjectiveData* Objective, FGameplayTag Tag) const;

    UFUNCTION(BlueprintPure)
    TArray<FGameplayTag> GetMissionPoints();

    UFUNCTION(BlueprintCallable)
    FText GetMissionName() const;

    UFUNCTION(BlueprintCallable)
    FText GetMissionDescription() const;

    UFUNCTION(BlueprintCallable)
    FGameplayTag GetMissionCategoryID() const;

    UFUNCTION(BlueprintCallable)
    FGameplayTag GetMainObjectivePoint() const;

    UFUNCTION(BlueprintCallable)
    FGameplayTag GetMainObjectiveLevel() const;

    UFUNCTION(BlueprintCallable)
    FString GetItemUID(UMissionAbstractObjectiveData* Objective, int32 Index) const;

    UFUNCTION(BlueprintCallable)
    void GetDuration(bool& bHaveDuration, FString& FinishDateString);

    UFUNCTION(BlueprintCallable)
    bool FinishObjective(UMissionAbstractObjectiveData* Objective, bool bIgnoreTutorialDelivery);

    UFUNCTION(BlueprintCallable)
    bool FinishAllObjectives(bool bIgnoreTutorialDelivery);

    UFUNCTION(BlueprintCallable)
    bool CheckPrimaryObjectivesCompleted();

    UFUNCTION(BlueprintCallable)
    void CheckDelivery(TArray<AActor*> ItemActors, bool bFinishObjectives, bool& bSuccess, TArray<AActor*>& ExcessiveActors);

    UFUNCTION(BlueprintCallable)
    void CheckCompletion(bool& bCompleted);

    UPROPERTY(BlueprintReadOnly)
    FString InstanceId;
    UPROPERTY(BlueprintReadOnly)
    FGameplayTag ConfigID;
    UPROPERTY(BlueprintReadOnly)
    bool Abortable;
    UPROPERTY(BlueprintReadOnly)
    EMissionState State;
    UPROPERTY(BlueprintReadOnly)
    TArray<UMissionAbstractObjectiveData*> Objectives;
    UPROPERTY(BlueprintReadOnly)
    TMap<FGameplayTag, FGameplayTag> AdditionalCorpsePointsToLoot;
    UPROPERTY(BlueprintReadOnly)
    TArray<FTagToTagsList> AdditionalPointsToNPCs;
    UPROPERTY(BlueprintReadOnly)
    float TimeCreated;
    UPROPERTY(BlueprintReadOnly)
    float TimeStarted;
    UPROPERTY(BlueprintReadOnly)
    float TimeFinished;
    UPROPERTY(BlueprintReadOnly)
    int32 TutorialStep;
    UPROPERTY()
    TMap<FString, FString> RawData;
};
