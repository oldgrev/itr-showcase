#include "PRItemDurabilityComponent.h"
#include "ITRDefaults.h"

UPRItemDurabilityComponent::UPRItemDurabilityComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickGroup"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bCanEverTick"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickInterval"), (double)0);
}

void UPRItemDurabilityComponent::OnTakePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser) {
}

void UPRItemDurabilityComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) {
}

bool UPRItemDurabilityComponent::ChangeDurability(float Damage, AActor* causer, FGameplayTag weponTag, const UDamageType* DamageType) {
    return {};
}

