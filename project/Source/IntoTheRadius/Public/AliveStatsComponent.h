#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "OnChangeHealthDelegate.h"
#include "OnDamagedDelegate.h"
#include "OnHealthEndDelegate.h"
#include "OnHungerEndDelegate.h"
#include "OnStaminaEndDelegate.h"
#include "OnStaminaLowDelegate.h"
#include "AliveStatsComponent.generated.h"

class AActor;
class AController;
class UDamageType;
class UObject;
class UPrimitiveComponent;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UAliveStatsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UAliveStatsComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UseStamina(bool bUse, float UseSpeed);

    UFUNCTION(BlueprintCallable)
    void OnTakePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser);

    UFUNCTION(BlueprintCallable)
    void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

    UFUNCTION(BlueprintCallable)
    void Kill();

    UFUNCTION(BlueprintPure)
    bool IsCriticalHit(const UObject* HitComponent, FName BoneName);

    UFUNCTION(BlueprintPure)
    bool IsAlive();

    UFUNCTION(BlueprintCallable)
    void HealthRegeneration();

    UFUNCTION(BlueprintPure)
    float GetHealthPercent();

    UFUNCTION(BlueprintCallable)
    void DisplayStats();

    UFUNCTION()
    void CustomTick();

    UFUNCTION(BlueprintCallable)
    void ChangeHealth(float Value);

    UFUNCTION(BlueprintCallable)
    void CalculateStamina(bool bUse);

    UFUNCTION(BlueprintCallable)
    float ApplyDamage(AActor* causer, AActor* Weapon, float InputDamage);

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float Health;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float MaxHealth;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bRegeneration;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float MaxRegenHealth;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float RegenerationSpeed;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float RegenHealthLowLevel;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bNoHealth;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bAutoRegeneration;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bAllowAutoRegeneration;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bLowHealth;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float Stamina;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float StaminaMax;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float StaminaSpeed;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bStaminaUse;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bStaminaEnded;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bLowStamina;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    AActor* OwnerActor;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bIgnoreNextAnyDamage;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    AActor* LastDamageCauser;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    FGameplayTag LastDamageByWeapon;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool LastDamageWithSmoothing;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> LastDamageByActor;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    FName CritBoneName;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UObject* CritComponent;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bPrintStats;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bCritsOnly;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bCanDie;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UDamageType* IgnoredDamageType;
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnHungerEnd OnHungerEnd;
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnHealthEnd OnHealthEnd;
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnStaminaEnd OnStaminaEnd;
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnStaminaLow OnStaminaLow;
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnDamaged OnDamaged;
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnChangeHealth OnChangeHealth;
};
