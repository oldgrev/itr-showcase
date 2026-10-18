#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "AmmoInfo.h"
#include "BulletComponentApplyDamageDelegate.h"
#include "BulletComponentDestroyDelegate.h"
#include "BulletComponentImpactDelegate.h"
#include "BulletComponentRicochetDelegate.h"
#include "PRBasicActorComponent.h"
#include "RadiusBulletComponent.generated.h"

class AActor;
class UPhysicalMaterial;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API URadiusBulletComponent : public UPRBasicActorComponent {
    GENERATED_BODY()
public:
    URadiusBulletComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ProcessHit(const FHitResult& HitResult, const FVector& Velocity);

    UFUNCTION(BlueprintCallable)
    void Initialize(const FAmmoInfo& AmmoInfo, const float MuzzleVelocity, const float BaseDamage);

private:
    UPROPERTY()
    FAmmoInfo _ammoInfo;
    UPROPERTY()
    TWeakObjectPtr<AActor> _hitActor;
protected:
    UPROPERTY(EditDefaultsOnly)
    FName BulletTag;
    UPROPERTY(EditDefaultsOnly)
    float MaxImpactVelocity;
    UPROPERTY(EditDefaultsOnly)
    float DefaultDensity;
    UPROPERTY(EditDefaultsOnly)
    float NoiseLoudness;
    UPROPERTY(EditDefaultsOnly)
    float NoiseRange;
    UPROPERTY(EditDefaultsOnly)
    UPhysicalMaterial* DefaultMaterial;
    UPROPERTY(EditDefaultsOnly)
    UPhysicalMaterial* MetalMaterial;
    UPROPERTY(EditDefaultsOnly)
    FVector2D RicochetDegreesRange;
    UPROPERTY(EditDefaultsOnly)
    float PenetrationScale;
    UPROPERTY(EditDefaultsOnly)
    FVector2D PenetrationDensityInputRange;
    UPROPERTY(EditDefaultsOnly)
    FVector2D PenetrationDensityOutputRange;
    UPROPERTY(EditDefaultsOnly)
    FVector2D PenetrationConeDegreesRange;
    UPROPERTY(EditDefaultsOnly)
    float RicochetForceScale;
    UPROPERTY(EditDefaultsOnly)
    FVector2D DamageScaleRange;
public:
    UPROPERTY(BlueprintAssignable)
    FBulletComponentImpact OnImpact;
    UPROPERTY(BlueprintAssignable)
    FBulletComponentRicochet OnRicochet;
    UPROPERTY(BlueprintAssignable)
    FBulletComponentApplyDamage OnApplyDamage;
    UPROPERTY(BlueprintAssignable)
    FBulletComponentDestroy OnDestroy;
};
