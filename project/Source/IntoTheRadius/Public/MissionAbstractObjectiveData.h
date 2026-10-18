#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EMissionObjectiveImportance.h"
#include "MissionAbstractObjectiveData.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionAbstractObjectiveData : public UObject {
    GENERATED_BODY()
public:
    UMissionAbstractObjectiveData(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    virtual bool HaveDelivery();

    UFUNCTION(BlueprintCallable)
    int32 GetRewardMoney() const;

    UFUNCTION(BlueprintPure)
    FText GetObjectiveShortName();

    UFUNCTION(BlueprintPure)
    FText GetObjectiveLongName();

    UFUNCTION(BlueprintPure)
    virtual TArray<FGameplayTag> GetMissionPoints();

    UFUNCTION(BlueprintPure)
    virtual FString GetDeliveryCountString();

    UFUNCTION(BlueprintPure)
    virtual int32 GetDeliveryCountObjectives();

    UFUNCTION(BlueprintPure)
    virtual FString GetCountString();

    UFUNCTION(BlueprintPure)
    virtual int32 GetCountObjectives();

    UFUNCTION(BlueprintCallable)
    virtual void CollectDeliveryTags(TArray<FGameplayTag>& DeliveryTags);

    UFUNCTION(BlueprintCallable)
    virtual bool CheckObjectiveCompletion();

    UPROPERTY(BlueprintReadOnly)
    EMissionObjectiveImportance Importance;
    UPROPERTY(BlueprintReadOnly)
    int32 RewardMoney;
    UPROPERTY(BlueprintReadOnly)
    int32 RewardPlayerLevel;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Finished;
};
