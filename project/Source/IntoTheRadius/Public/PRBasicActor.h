#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "RelevanceDescription.h"
#include "PRBasicActor.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRBasicActor : public AActor {
    GENERATED_BODY()
public:
    APRBasicActor(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintNativeEvent)
    void OnTransitionStart();

    UFUNCTION(BlueprintNativeEvent)
    void OnTransitionEnd();

    UFUNCTION(BlueprintNativeEvent)
    void OnLevelStarted(const FGameplayTag LevelTag);

    UFUNCTION(BlueprintNativeEvent)
    void OnLevelPrepare(const FGameplayTag LevelTag);

private:
    UFUNCTION()
    void OnGameStartedPrivate();

protected:
    UFUNCTION(BlueprintNativeEvent)
    void OnGameStarted();

    UFUNCTION(BlueprintNativeEvent)
    void OnGamePaused(const bool bPaused);

    UFUNCTION(BlueprintCallable)
    void DisableRelevanceManagement();

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    bool UseRelevanceManagement;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    TArray<FRelevanceDescription> RelevanceDescription;
};
