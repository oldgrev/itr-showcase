#include "RadiusPlayerMovementComponent.h"
#include "ITRDefaults.h"

URadiusPlayerMovementComponent::URadiusPlayerMovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickGroup"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bCanEverTick"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickInterval"), (double)0);
}

void URadiusPlayerMovementComponent::StopMovement() {
}

void URadiusPlayerMovementComponent::ProcessMovementTeleport(const float DeltaSeconds) {
}

void URadiusPlayerMovementComponent::ProcessMovementNormal(const float DeltaSeconds) {
}

void URadiusPlayerMovementComponent::ProcessMovement(const float DeltaSeconds) {
}

TArray<FTeleportPointInfo> URadiusPlayerMovementComponent::PreparePointsToTeleport(const FVector& From, const FVector& To) {
    return {};
}

bool URadiusPlayerMovementComponent::IsTeleporting() const {
    return {};
}

