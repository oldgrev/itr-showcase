#include "RadiusBulletComponent.h"
#include "ITRDefaults.h"

URadiusBulletComponent::URadiusBulletComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickGroup"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bCanEverTick"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickInterval"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("_ammoInfo.ItemTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("_ammoInfo.AmmoCaliberID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("_ammoInfo.AmmoTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("_ammoInfo.VelocityMultiplier"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("_ammoInfo.BounceMax"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("_ammoInfo.DamageModifier"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("BulletTag"), TEXT("Bullet"));
    ITRDefaults::Set(GetClass(), this, TEXT("MaxImpactVelocity"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("DefaultDensity"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("NoiseLoudness"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("NoiseRange"), (double)800);
    ITRDefaults::Set(GetClass(), this, TEXT("RicochetDegreesRange.X"), (double)45);
    ITRDefaults::Set(GetClass(), this, TEXT("RicochetDegreesRange.Y"), (double)360);
    ITRDefaults::Set(GetClass(), this, TEXT("PenetrationScale"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("PenetrationDensityInputRange.X"), (double)0.100000001);
    ITRDefaults::Set(GetClass(), this, TEXT("PenetrationDensityInputRange.Y"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("PenetrationDensityOutputRange.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("PenetrationDensityOutputRange.Y"), (double)20);
    ITRDefaults::Set(GetClass(), this, TEXT("PenetrationConeDegreesRange.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PenetrationConeDegreesRange.Y"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("RicochetForceScale"), (double)0.5);
    ITRDefaults::Set(GetClass(), this, TEXT("DamageScaleRange.X"), (double)0.25);
    ITRDefaults::Set(GetClass(), this, TEXT("DamageScaleRange.Y"), (double)1);
}

void URadiusBulletComponent::ProcessHit(const FHitResult& HitResult, const FVector& Velocity) {
}

void URadiusBulletComponent::Initialize(const FAmmoInfo& AmmoInfo, const float MuzzleVelocity, const float BaseDamage) {
}

