#include "AliveStatsComponent.h"
#include "ITRDefaults.h"

UAliveStatsComponent::UAliveStatsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickGroup"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bStartWithTickEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickInterval"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("Health"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxHealth"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxRegenHealth"), (double)80);
    ITRDefaults::Set(GetClass(), this, TEXT("RegenerationSpeed"), (double)0.100000001);
    ITRDefaults::Set(GetClass(), this, TEXT("RegenHealthLowLevel"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("Stamina"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("StaminaMax"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("StaminaSpeed"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("LastDamageByWeapon.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("bPrintStats"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("bCanDie"), true);
}

void UAliveStatsComponent::UseStamina(bool bUse, float UseSpeed) {
}

void UAliveStatsComponent::OnTakePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser) {
}

void UAliveStatsComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) {
}

void UAliveStatsComponent::Kill() {
}

bool UAliveStatsComponent::IsCriticalHit(const UObject* HitComponent, FName BoneName) {
    return {};
}

bool UAliveStatsComponent::IsAlive() {
    return {};
}

void UAliveStatsComponent::HealthRegeneration() {
}

float UAliveStatsComponent::GetHealthPercent() {
    return {};
}

void UAliveStatsComponent::DisplayStats() {
}

void UAliveStatsComponent::CustomTick() {
}

void UAliveStatsComponent::ChangeHealth(float Value) {
}

void UAliveStatsComponent::CalculateStamina(bool bUse) {
}

float UAliveStatsComponent::ApplyDamage(AActor* causer, AActor* Weapon, float InputDamage) {
    return {};
}

