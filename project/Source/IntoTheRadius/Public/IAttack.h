#pragma once

#include "CoreMinimal.h"
#include "IAttack.generated.h"

class AActor;
class USceneComponent;

UINTERFACE(MinimalAPI, Blueprintable)
class UIAttack : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIAttack {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void StopAttack();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void StartAttack();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetWeaponVisible(bool bVisible);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void Reload();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OwnerInitialised();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnOutOfAmmo();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnMeleeAttackHit();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool NeedWaitForFinish() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsReloading() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsReadyToAttack();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsAttackValid();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsAttacking() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    AActor* GetWeaponActor();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    USceneComponent* GetFirePointComponent();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetAttackDistance();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void DestroyWeapon();

};
