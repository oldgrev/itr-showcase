#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "NpcPointQueryResult.h"
#include "RelevanceDescription.h"
#include "PRBasicCharacter.generated.h"

UCLASS(Blueprintable, BlueprintType, Config=Game)
class INTOTHERADIUS_API APRBasicCharacter : public ACharacter {
    GENERATED_BODY()
public:
    APRBasicCharacter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetCoverReservationFromSearchResult(const FNpcPointQueryResult& Result);

protected:
    UFUNCTION(BlueprintNativeEvent)
    void OnTransitionStart();

    UFUNCTION(BlueprintNativeEvent)
    void OnTransitionEnd();

    UFUNCTION(BlueprintNativeEvent)
    void OnLevelStarted(FGameplayTag LevelTag);

    UFUNCTION(BlueprintNativeEvent)
    void OnLevelPrepare(FGameplayTag LevelTag);

private:
    UFUNCTION()
    void OnGameStartedPrivate();

protected:
    UFUNCTION(BlueprintNativeEvent)
    void OnGameStarted();

    UFUNCTION(BlueprintNativeEvent)
    void OnGamePaused(const bool bPaused);

    UFUNCTION(BlueprintNativeEvent)
    void OnGameDataSaved();

    UFUNCTION(BlueprintCallable)
    bool GetRandomReachablePoint(FVector Origin, float Radius, FVector StartPoint, float MinDistance, FVector& Point);

public:
    UFUNCTION(BlueprintCallable)
    void ClearCoverReservation();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    bool UseRelevanceManagement;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    TArray<FRelevanceDescription> RelevanceDescription;
};
