#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "DamageDealerInterface.h"
#include "IAnomaly.h"
#include "IInstanceID.h"
#include "IPooledActor.h"
#include "PRBasicActor.h"
#include "PRAnomaly.generated.h"

class AActor;
class UAudioComponent;
class UDamageType;
class UPrimitiveComponent;
class USceneComponent;
class USoundBase;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRAnomaly : public APRBasicActor, public IIAnomaly, public IIInstanceID, public IDamageDealerInterface, public IIPooledActor {
    GENERATED_BODY()
public:
    APRAnomaly(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION()
    void TriggerVisuals();

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OverlapTriggered(AActor* OtherActor);

    UFUNCTION(BlueprintImplementableEvent)
    void OverlapStartingTriggered(AActor* OtherActor);

    UFUNCTION(BlueprintImplementableEvent)
    void OverlapLeavingTriggered(AActor* OtherActor);

private:
    UFUNCTION()
    void OverlapCheckerDelegate();

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnSetupEvent();

protected:
    UFUNCTION()
    void OnOverlapEndTrigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UFUNCTION()
    void OnOverlapBeginTrigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
    UFUNCTION(BlueprintCallable)
    void LevelStarted(FGameplayTag LevelTag);

    UFUNCTION(BlueprintCallable)
    void LevelPrepare(FGameplayTag LevelTag);

    UFUNCTION(BlueprintCallable)
    void GenerateTriggersOverlapEvents(bool ClearExistingEvents);

protected:
    UFUNCTION(BlueprintCallable)
    void ApplyAnomalyDamage(AActor* Actor);

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void AnomalyTriggered();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    float AnomalyRadius;
protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    USceneComponent* Root;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UAudioComponent* Audio;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UPrimitiveComponent* Trigger;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 MinVisTrigger;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 MaxVisTrigger;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float SignificanceDistance;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float EffectDelay;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool AlwaysSignificant;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag TypeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool Significant;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool IsAnomalyTriggered;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 RandomTime;
public:
    UPROPERTY(EditDefaultsOnly)
    float AnomalyBaseDamage;
protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    USoundBase* ConstSound;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TSubclassOf<UDamageType> DamageType;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool SelfTriggering;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool NDebug;
protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float TriggeredOverlapCheckTimer;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsSoundConstant;
protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DotDuration;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool HasAudio;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool AffectsOnlyPlayer;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool BeginOverlapAffectsActorsMultipleTimesIfBlink;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IgnorePlayerInventory;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true))
    FString CustomUID;
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<AActor*> ActorsAffected;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<UPrimitiveComponent*> Triggers;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<USceneComponent*> DeactivatedComps;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<USceneComponent*> HiddenComps;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTimerHandle OverlapTriggerTimerHandle;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTimerHandle OverlapCheckerTimer;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTimerHandle significantTimer;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTimerHandle SelfTriggerTimer;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTimerHandle discoverTimer;
};
