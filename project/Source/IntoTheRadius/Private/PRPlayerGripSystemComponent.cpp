#include "PRPlayerGripSystemComponent.h"
#include "DistanceGripManager.h"
#include "ITRDefaults.h"

UPRPlayerGripSystemComponent::UPRPlayerGripSystemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UDistanceGripManager* Sub0 = Cast<UDistanceGripManager>(GetDefaultSubobjectByName(TEXT("Distance Grip Manager")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UDistanceGripManager>(TEXT("Distance Grip Manager"));
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickGroup"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bStartWithTickEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickInterval"), (double)0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("DistanceGripManager"), GetDefaultSubobjectByName(TEXT("Distance Grip Manager")));
}

void UPRPlayerGripSystemComponent::UnregisterForDistanceGrip(UInventoryItem* Item) {
}

void UPRPlayerGripSystemComponent::ToggleDebugDrawDistanceGrip() {
}

void UPRPlayerGripSystemComponent::RegisterForDistanceGrip(UInventoryItem* Item) {
}

void UPRPlayerGripSystemComponent::PerformOverlapGrip(const bool isLeftHand, const TArray<AActor*>& otherHandGrippedActors, const USphereComponent* GripSphere, const FTransform& HandWorldTransform, const FVector& handRootLocation, const UGripMotionControllerComponent* MotionController, UPrimitiveComponent*& CompToGrip, UPrimitiveComponent*& triggerToGrip, FTransform& triggerTransform) {
}

void UPRPlayerGripSystemComponent::PerformDistanceGrip(const USphereComponent* GripSphere, UPrimitiveComponent*& CompToGrip, FVector& CompHitLoc, FVector& DistanceGripPoint) {
}

void UPRPlayerGripSystemComponent::IsDebugDrawDistanceGrip(bool& bDebugDrawing) const {
}

