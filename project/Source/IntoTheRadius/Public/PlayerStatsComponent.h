#pragma once

#include "CoreMinimal.h"
#include "EPRStatStatus.h"
#include "IHealthStatus.h"
#include "NoParamsDelegate.h"
#include "PRBasicActorComponent.h"
#include "StatStatusEventDelegate.h"
#include "PlayerStatsComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UPlayerStatsComponent : public UPRBasicActorComponent, public IIHealthStatus {
    GENERATED_BODY()
public:
    UPlayerStatsComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UseStamina(bool Use, float StaminaUseMult);

    UFUNCTION(BlueprintCallable)
    void SetStats(const int32 HealthPercent, const int32 StaminaPercent, const int32 RestPercent, const int32 NutritionPercent, const int32 HungerPercent);

    UFUNCTION(BlueprintCallable)
    void SetStamina(const float Value);

    UFUNCTION(BlueprintCallable)
    void SetHealth(float Health);

    UFUNCTION(BlueprintCallable)
    void Reset(bool bAlive);

    UFUNCTION(BlueprintCallable)
    void RegenerateHealth(float DeltaSeconds);

    UFUNCTION(BlueprintPure)
    bool HasStamina();

    UFUNCTION(BlueprintPure)
    bool HasRest();

    UFUNCTION(BlueprintPure)
    bool HasNutrition();

    UFUNCTION(BlueprintPure)
    static void GetStatus(EPRStatStatus& Health, EPRStatStatus& Stamina, EPRStatStatus& Nutrition);

    UFUNCTION(BlueprintPure)
    void GetStats(float& Health, float& HealthPercent, float& Stamina, float& StaminaPercent, float& Rest, float& RestPercent, float& Nutrition, float& NutritionPercent);

    UFUNCTION(BlueprintPure)
    void GetStaminaPercent(float& StaminaPercent);

    UFUNCTION(BlueprintPure)
    void GetSleepTimeTillRested(const int32 RestPercent, float& Seconds);

    UFUNCTION(BlueprintPure)
    void GetSleepTimeTillHealed(const int32 HealthPercent, float& Seconds);

    UFUNCTION(BlueprintPure)
    void GetRestPercent(float& RestPercent);

    UFUNCTION(BlueprintPure)
    void GetMaxAvailableStamina(float& Stamina, float& MaxAvailable);

    UFUNCTION(BlueprintPure)
    void GetHealthMax(float& HealthMax);

    UFUNCTION(BlueprintPure)
    bool EnoughStamina(const float Stamina);

    UFUNCTION(BlueprintCallable)
    void ChangeStamina(const float Delta);

    UFUNCTION(BlueprintCallable)
    void ChangeRestByPercent(const int32 Percent);

    UFUNCTION(BlueprintCallable)
    void ChangeRest(const float Delta, const bool bBuff);

    UFUNCTION(BlueprintCallable)
    void ChangeNutrition(const float Delta);

    UFUNCTION(BlueprintCallable)
    void ChangeHealthByPercent(int32 Percent);

    UFUNCTION(BlueprintPure)
    bool CanRegenerateHealth();

    UFUNCTION(BlueprintCallable)
    void AllowRegeneration(float HealthRegenStart, float HealthRegenMax, float HealthRegenPerSecond);

    UPROPERTY(BlueprintAssignable)
    FStatStatusEvent OnHealth;
    UPROPERTY(BlueprintAssignable)
    FStatStatusEvent OnStamina;
    UPROPERTY(BlueprintAssignable)
    FStatStatusEvent OnNutrition;
    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnBlackout;
};
