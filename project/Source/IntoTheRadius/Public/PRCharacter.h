#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ActorVolumeActivationInterface.h"
#include "EAwarenessLevel.h"
#include "ECharCommand.h"
#include "ECharDetailLevel.h"
#include "IBotPawn.h"
#include "ICommandEvents.h"
#include "IHealthStatus.h"
#include "IInstanceID.h"
#include "INPC.h"
#include "NPCGameData.h"
#include "NpcPointQueryResult.h"
#include "PRBasicCharacter.h"
#include "PRNPCInfo.h"
#include "PlayerLightSensitiveInterface.h"
#include "PRCharacter.generated.h"

class AAIController;
class AActor;
class UAIEdPerceptionComp;
class UAIPerceptionStimuliSourceComponent;
class UActorComponent;
class UAliveStatsComponent;
class UAudioComponent;
class UBehaviorTree;
class UBlackboardComponent;
class UObject;
class UPRNpcPerceptionComponent;
class UWidgetComponent;

UCLASS(Blueprintable, BlueprintType, Config=Game)
class INTOTHERADIUS_API APRCharacter : public APRBasicCharacter, public IINPC, public IIInstanceID, public IIHealthStatus, public IPlayerLightSensitiveInterface, public IIBotPawn, public IICommandEvents, public IActorVolumeActivationInterface {
    GENERATED_BODY()
public:
    APRCharacter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void WalkToLocation(const FVector Location);

    UFUNCTION(BlueprintCallable)
    void WalkToActorLocation(AActor* Actor);

protected:
    UFUNCTION()
    void SwitchAiDebug();

public:
    UFUNCTION(BlueprintCallable)
    void SpawnLoot() const;

    UFUNCTION(BlueprintCallable)
    void SetupState(const FNPCGameData& NPC_data, TArray<FName> BoolNames, TArray<bool> BoolValues);

    UFUNCTION(BlueprintCallable)
    void SetEnableEverything(const bool enable);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetEnableAdditionalThings(bool enable);

    UFUNCTION(BlueprintCallable)
    void SetCommand(ECharCommand NewCommand, bool Force);

    UFUNCTION(BlueprintCallable)
    void SetBrainEnabled(const bool enable) const;

    UFUNCTION(BlueprintCallable)
    bool SelectAndAttackClosest();

    UFUNCTION(BlueprintCallable)
    bool SelectAndAttack(AActor* Actor);

    UFUNCTION(BlueprintCallable)
    void SaveGameData();

    UFUNCTION(BlueprintCallable)
    void RestartTree() const;

private:
    UFUNCTION(BlueprintCallable)
    void ReappearOutOfSight();

    UFUNCTION(BlueprintCallable)
    void ReappearCoverCallback(const FNpcPointQueryResult& QueryResult);

public:
    UFUNCTION(BlueprintCallable)
    void ProcessNoise(const FName Tag, const FVector Location);

    UFUNCTION(BlueprintCallable)
    void ProcessDamage(AActor* causer, float Damage);

    UFUNCTION(BlueprintCallable)
    void PrintMessage(const FString& MessageToPrint) const;

    UFUNCTION()
    void OnHeardNoise(AActor* Actor, FVector Location, float Strength, FName Tag);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnDeath(bool bEnableRagdoll);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnDamaged(AActor* causer, const float Damage);

private:
    UFUNCTION()
    void NpcAwarenessLevelChanged(const EAwarenessLevel PrevLevel, const EAwarenessLevel NewLevel);

public:
    UFUNCTION(BlueprintCallable)
    void LoadBaseSettings();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void LoadAdditionalSettings();

    UFUNCTION(BlueprintCallable)
    bool IsPlayerNear() const;

    UFUNCTION(BlueprintCallable)
    bool IsLocInValidRange(FVector Location) const;

    UFUNCTION(BlueprintCallable)
    bool IsEnabled() const;

    UFUNCTION(BlueprintCallable)
    void InvestigateLocation(FVector Location);

    UFUNCTION()
    void HealthEnd();

    UFUNCTION(BlueprintCallable)
    FVector GetIdleOriginPoint() const;

    UFUNCTION(BlueprintCallable)
    float GetFootstepNoiseRange() const;

    UFUNCTION(BlueprintCallable)
    EAwarenessLevel GetAwarenessLevel() const;

    UFUNCTION(BlueprintCallable)
    float GetAttackMoveDilationAngle() const;

    UFUNCTION(BlueprintCallable)
    float GetAttackLostLocationTime() const;

    UFUNCTION(BlueprintCallable)
    void EnableRagdoll();

    UFUNCTION(BlueprintCallable)
    void DestroyController();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void CharEnabled();

    UFUNCTION()
    void AlertNearbyMonsters(AActor* causer, const bool bDeath);

protected:
    UPROPERTY(EditDefaultsOnly)
    UWidgetComponent* DebugWidget;
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UPRNpcPerceptionComponent* PerceptionComponent;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UAudioComponent* AudioIdle;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UAIPerceptionStimuliSourceComponent* AIPerceptionStimuliSource;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UAIEdPerceptionComp* AIEdPerceptionComponent;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UAliveStatsComponent* AliveStatsComponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName CommandKeyName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UBehaviorTree* BTAsset;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WalkSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float IdleTime;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLookAroundAfterWalk;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LootPossibility;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag NPCTag;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* IdleOrigin;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStrictOrigin;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDebugInfo;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* CritComponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float IdleWalkRadius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName CharName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    float LootPossibilityOverride;
    UPROPERTY(BlueprintReadWrite)
    ECharCommand Command;
    UPROPERTY(BlueprintReadWrite)
    FVector POI;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float ValidDistanceToPlayer;
    UPROPERTY(BlueprintReadWrite)
    bool bEnabled;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    FString SpawnerId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    FString CustomUID;
    UPROPERTY(BlueprintReadWrite)
    bool bAlertCooldown;
protected:
    UPROPERTY(BlueprintReadWrite)
    ECharDetailLevel CurrentDetailLevel;
public:
    UPROPERTY(BlueprintReadWrite)
    AAIController* AIC;
    UPROPERTY(BlueprintReadWrite)
    UBlackboardComponent* BB;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLerpMovement;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> LootItemClass;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRNPCInfo NpcInfo;
protected:
    UPROPERTY()
    UActorComponent* ShootingComponent;
};
