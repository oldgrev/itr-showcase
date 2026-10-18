#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "EStorageDoorState.h"
#include "NoParamsDelegate.h"
#include "PRVRGripSMComponent.h"
#include "StorageDoorComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UStorageDoorComponent : public UPRVRGripSMComponent, public IGameplayTagAssetInterface {
    GENERATED_BODY()
public:
    UStorageDoorComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

    UFUNCTION(BlueprintCallable)
    void SetLock(bool lock);

    UFUNCTION(BlueprintCallable)
    void Open();

private:
    UFUNCTION()
    void OnTick();

    UFUNCTION()
    void OnLevelStarted(FGameplayTag LevelTag);

    UFUNCTION()
    void OnGameStarted();

public:
    UFUNCTION(BlueprintCallable)
    bool IsOpened() const;

    UFUNCTION(BlueprintCallable)
    bool IsClosed() const;

    UFUNCTION(BlueprintCallable)
    void GetCurrentState(EStorageDoorState& CurrentState) const;

    UFUNCTION(BlueprintCallable)
    void Close();

    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnDoorStateChanged;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnDoorFinishedLerping;
    UPROPERTY(BlueprintReadOnly)
    float CurrentAngle;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AngleLimit;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AngleSnap;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector ControlVectorNormal;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTagContainer GameplayTags;
};
