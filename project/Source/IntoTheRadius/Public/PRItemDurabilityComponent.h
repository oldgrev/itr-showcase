#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemDamagedDelegate.h"
#include "NoParamsDelegate.h"
#include "PRBasicActorComponent.h"
#include "PRItemDurabilityComponent.generated.h"

class AActor;
class AController;
class UDamageType;
class UPrimitiveComponent;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UPRItemDurabilityComponent : public UPRBasicActorComponent {
    GENERATED_BODY()
public:
    UPRItemDurabilityComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION()
    void OnTakePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser);

    UFUNCTION()
    void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

public:
    UFUNCTION(BlueprintCallable)
    bool ChangeDurability(float Damage, AActor* causer, FGameplayTag weponTag, const UDamageType* DamageType);

    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnDestroyed;
    UPROPERTY(BlueprintAssignable)
    FItemDamagedDelegate OnDamaged;
};
