#pragma once

#include "CoreMinimal.h"
#include "PRBasicActorComponent.h"
#include "PRPlayerGripSystemComponent.generated.h"

class AActor;
class APRPlayerCharacter;
class UDistanceGripManager;
class UGripMotionControllerComponent;
class UInventoryItem;
class UPrimitiveComponent;
class USphereComponent;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UPRPlayerGripSystemComponent : public UPRBasicActorComponent {
    GENERATED_BODY()
public:
    UPRPlayerGripSystemComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UnregisterForDistanceGrip(UInventoryItem* Item);

    UFUNCTION(BlueprintCallable)
    void ToggleDebugDrawDistanceGrip();

    UFUNCTION(BlueprintCallable)
    void RegisterForDistanceGrip(UInventoryItem* Item);

    UFUNCTION(BlueprintCallable)
    void PerformOverlapGrip(const bool isLeftHand, const TArray<AActor*>& otherHandGrippedActors, const USphereComponent* GripSphere, const FTransform& HandWorldTransform, const FVector& handRootLocation, const UGripMotionControllerComponent* MotionController, UPrimitiveComponent*& CompToGrip, UPrimitiveComponent*& triggerToGrip, FTransform& triggerTransform);

    UFUNCTION(BlueprintCallable)
    void PerformDistanceGrip(const USphereComponent* GripSphere, UPrimitiveComponent*& CompToGrip, FVector& CompHitLoc, FVector& DistanceGripPoint);

    UFUNCTION(BlueprintCallable)
    void IsDebugDrawDistanceGrip(bool& bDebugDrawing) const;

private:
    UPROPERTY()
    APRPlayerCharacter* OwningPlayer;
    UPROPERTY()
    UDistanceGripManager* DistanceGripManager;
};
