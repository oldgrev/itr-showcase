#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "EWeaponBoltState.h"
#include "OneParamBoltStateDelegate.h"
#include "PRVRGripSMComponent.h"
#include "WeaponBoltComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UWeaponBoltComponent : public UPRVRGripSMComponent, public IGameplayTagAssetInterface {
    GENERATED_BODY()
public:
    UWeaponBoltComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

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
    void GetCurrentState(EWeaponBoltState& CurrentState) const;

    UFUNCTION(BlueprintCallable)
    void Drop();

    UPROPERTY(BlueprintAssignable)
    FOneParamBoltState OnBoltStateChanged;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AngleLimit;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AutoCloseRotateOnRelease;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SnapPercent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SlideLimit;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StickToOpen;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationCoeff;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SlideCoeff;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTagContainer GameplayTags;
};
