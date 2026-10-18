#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Perception/AIPerceptionTypes.h"
#include "EAwarenessLevel.h"
#include "IBotComponent.h"
#include "NPCAwarenessConfig.h"
#include "NPCPerceptionConfig.h"
#include "OnAwarenessLevelChangedDelegate.h"
#include "OnHeardNoiseDelegate.h"
#include "OnHeardNoiseNewDelegate.h"
#include "OneParamActorDelegate.h"
#include "PRBasicSceneComponent.h"
#include "PRNPCInfo.h"
#include "PlayerLostDelegate.h"
#include "TwoParamsActorVectorDelegate.h"
#include "PRNpcPerceptionComponent.generated.h"

class AAIController;
class AActor;
class APRPlayerCharacter;
class APRPointOfInterest;
class UAIEdPerceptionComp;
class UAIPerceptionComponent;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UPRNpcPerceptionComponent : public UPRBasicSceneComponent, public IIBotComponent {
    GENERATED_BODY()
public:
    UPRNpcPerceptionComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void VerifyPlayerSelection();

    UFUNCTION(BlueprintCallable)
    void UnselectPlayer();

    UFUNCTION(BlueprintCallable)
    void SpotPlayer();

    UFUNCTION(BlueprintCallable)
    void SpotActor(const AActor* Actor);

    UFUNCTION(BlueprintCallable)
    void SetupInitialState(float InitialAwareness, bool bPlayerInitiallySelected);

    UFUNCTION(BlueprintCallable)
    void SetSelection(const AActor* Actor, bool& bSuccess, AActor*& Selection);

    UFUNCTION(BlueprintCallable)
    void SetPoiFollowSelection(const bool bShouldFollow);

    UFUNCTION(BlueprintCallable)
    void SetPoi(const FVector& NewPoi, bool& bChanged, AActor*& POIActor);

    UFUNCTION(BlueprintCallable)
    void SelectPlayer();

    UFUNCTION(BlueprintCallable)
    void SelectionIsAlive(bool& bAlive) const;

    UFUNCTION(BlueprintCallable)
    void IsSpotted(const AActor* Actor, bool& bSpotted) const;

    UFUNCTION(BlueprintCallable)
    void IsPlayerSpotted(bool& bSpotted) const;

    UFUNCTION(BlueprintCallable)
    void IsPlayerSelectionAlive(bool& bAlive) const;

    UFUNCTION(BlueprintCallable)
    void IsEnemy(const AActor* Actor, bool& bIsEnemy) const;

    UFUNCTION(BlueprintCallable)
    void IsActorSpottable(const AActor* Actor, bool& bSpottable) const;

    UFUNCTION(BlueprintCallable)
    void HaveSelection(bool& bValid);

    UFUNCTION(BlueprintCallable)
    void GetSensedPlayerLocation(bool& bValid, FVector& Location);

    UFUNCTION(BlueprintCallable)
    void GetSelection(bool& bValid, AActor*& Selection, FTransform& BodyTransform) const;

    UFUNCTION(BlueprintPure)
    void GetPoi(bool& bValid, AActor*& POIActor);

    UFUNCTION(BlueprintCallable)
    void GetPlayerSelection(bool& bValid, AActor*& Player, FTransform& BodyTransform) const;

    UFUNCTION(BlueprintCallable)
    void GetClosestActor(bool& bSuccess, AActor*& Actor) const;

    UFUNCTION(BlueprintCallable)
    void GetAwareness(float& Value, EAwarenessLevel& Level) const;

    UFUNCTION(BlueprintCallable)
    void ChangeAwarenessByTag(float Strength, FName Tag);

    UFUNCTION(BlueprintCallable)
    void ChangeAwareness(float Value);

private:
    UFUNCTION()
    void AIPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus);

public:
    UPROPERTY(BlueprintAssignable, Transient)
    FOneParamActor OnSpottedPlayer;
    UPROPERTY(BlueprintAssignable, Transient)
    FPlayerLostDelegate OnLostPlayer;
    UPROPERTY(BlueprintAssignable, Transient)
    FOneParamActor OnPlayerSelectionChange;
    UPROPERTY(BlueprintAssignable, Transient)
    FTwoParamsActorVector OnPoiChange;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, Transient)
    FOnHeardNoise OnHeardNoise;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, Transient)
    FOnHeardNoiseNew OnHeardNoiseNew;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, Transient)
    FOnAwarenessLevelChanged OnAwarenessLevelChanged;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDebugInfoEnabled;
protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<APRPointOfInterest> PoiActorClass;
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UAIPerceptionComponent> AIEdPerceptionComponentClass;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SenseDurationSpottedThreshold;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SenseDurationLostThreshold;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bForgetDead;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPoiFollowSelection;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DebugHeight;
    UPROPERTY(BlueprintReadWrite)
    UAIEdPerceptionComp* AIPerceptionComponent;
    UPROPERTY(BlueprintReadWrite)
    FNPCPerceptionConfig PerceptionConfig;
    UPROPERTY(BlueprintReadWrite)
    FNPCAwarenessConfig AwarenessConfig;
    UPROPERTY(BlueprintReadWrite)
    FGameplayTag NPCConfigID;
    UPROPERTY(BlueprintReadWrite)
    FPRNPCInfo NpcInfo;
    UPROPERTY(BlueprintReadWrite)
    FString OwnerName;
    UPROPERTY(BlueprintReadWrite)
    AAIController* AIC;
    UPROPERTY(BlueprintReadWrite)
    APRPointOfInterest* NpcPoiActor;
    UPROPERTY(BlueprintReadWrite)
    APRPlayerCharacter* PlayerRef;
    UPROPERTY(BlueprintReadWrite)
    AActor* CurrentPlayerSelection;
    UPROPERTY(BlueprintReadWrite)
    float SenseTickTime;
    UPROPERTY(BlueprintReadWrite)
    float SightSenseRadius;
    UPROPERTY(BlueprintReadWrite)
    float SightSenseNightModifier;
    UPROPERTY(BlueprintReadWrite)
    float SightSenseAngleLeft;
    UPROPERTY(BlueprintReadWrite)
    float SightSenseAngleRight;
    UPROPERTY(BlueprintReadWrite)
    float SightSenseAngleUp;
    UPROPERTY(BlueprintReadWrite)
    float SightSenseAngleDown;
    UPROPERTY(BlueprintReadWrite)
    float HearingDistance;
    UPROPERTY(BlueprintReadWrite)
    float AwarenessLowValueLevel;
    UPROPERTY(BlueprintReadWrite)
    float AwarenessHighValueLevel;
    UPROPERTY(BlueprintReadWrite)
    float AwarenessMaxValue;
    UPROPERTY(BlueprintReadWrite)
    float AwarenessDecreaseMultiplier;
    UPROPERTY(BlueprintReadWrite)
    EAwarenessLevel AwarenessLevel;
    UPROPERTY(BlueprintReadWrite)
    float AwarenessValue;
};
