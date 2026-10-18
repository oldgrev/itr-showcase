#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "ILevelPreparator.h"
#include "PRSublevelStreamingVolume.generated.h"

class UBoxComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRSublevelStreamingVolume : public AActor, public IILevelPreparator {
    GENERATED_BODY()
public:
    APRSublevelStreamingVolume(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateVolume();

private:
    UFUNCTION()
    void Reset();

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

public:
    UFUNCTION(BlueprintCallable)
    void LoadSublevels(bool evented);

    UFUNCTION(BlueprintCallable)
    bool IsLoaded();

    UFUNCTION(BlueprintCallable)
    bool CheckSphere(FVector Center, float Radius, float Coefficient);

    UFUNCTION(BlueprintCallable)
    bool CheckLocation(FVector Location, float Coefficient);

    UPROPERTY(BlueprintReadOnly)
    bool Triggered;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UBoxComponent* BoxVolume;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector VolumeExtent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FName> Sublevels;
};
