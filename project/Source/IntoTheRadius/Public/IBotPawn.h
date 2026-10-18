#pragma once

#include "CoreMinimal.h"
#include "EBotMovementMode.h"
#include "IBotPawn.generated.h"

class AActor;
class UActorComponent;
class UPRNpcPerceptionComponent;
class USplineComponent;

UINTERFACE(MinimalAPI, Blueprintable)
class UIBotPawn : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIBotPawn {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void TeleportToNextPos();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void StopMovement();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetTargetRotation(FRotator TargetRotation);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetFlyForce(FVector Force);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetBotMovementMode(EBotMovementMode MovementMode, bool& Changed);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ReportDeath(AActor* DeadActorRef);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnExitPlayerViewport();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnEnterPlayerViewport();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetStealth() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    AActor* GetSelection();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    UPRNpcPerceptionComponent* GetPerception();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetPatrolTargets(bool& IsValidOut, TArray<AActor*>& TargetsOut) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    USplineComponent* GetPatrolPath();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetOptimalRange();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetIdleWalkDistance() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FVector GetIdleOrigin();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    UActorComponent* GetBotShootingComponent();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    EBotMovementMode GetBotMovementMode() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FTransform GetBoneTransform(FName BoneName) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    UActorComponent* GetAliveStats();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void CcmStopWaitingForCombat();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void CcmStartWaitingForCombat();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void BroadcastEnemyLoc(const FVector Location, const bool bIsDead);

};
