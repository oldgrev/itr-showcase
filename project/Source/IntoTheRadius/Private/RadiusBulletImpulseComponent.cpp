#include "RadiusBulletImpulseComponent.h"
#include "ITRDefaults.h"

URadiusBulletImpulseComponent::URadiusBulletImpulseComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickGroup"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickInterval"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceDivider"), (double)100);
}

void URadiusBulletImpulseComponent::Suspend(bool IsSuspend) {
}

void URadiusBulletImpulseComponent::Stop() {
}

void URadiusBulletImpulseComponent::Start() {
}

void URadiusBulletImpulseComponent::Ricochet(const FVector& Location, const FVector& Force, const bool IsPenetration) {
}

void URadiusBulletImpulseComponent::Initialize(UPrimitiveComponent* TargetComponent, const float Mass, const float InitialVelocity, UCurveFloat* SpeedCurve) {
}

