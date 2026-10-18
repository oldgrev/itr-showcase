#pragma once

#include "CoreMinimal.h"
#include "VRBPDatatypes.h"
#include "PRPlayerPawn.generated.h"

class ABackpackSimple;
class UGripMotionControllerComponent;
class UPrimitiveComponent;

UINTERFACE(MinimalAPI, Blueprintable)
class UPRPlayerPawn : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IPRPlayerPawn {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SwitchBodyVisibility(const bool bVisible, const bool bRecursive);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ProcessMovementNative(const float DeltaSeconds);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    bool IsSecondaryGrip(const bool bLeft);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsBackpackInHands(const bool bCheckLeft, const bool bCheckRight);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsBackpackDropped();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    bool IsAnyLampEnabled();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    TArray<UPrimitiveComponent*> GetVisibilityPrimitives();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    float GetLightningCompensation();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    FVector GetInputMovementVector();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    float GetCrouch();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    ABackpackSimple* GetBackpackRef();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void DropGrip(UGripMotionControllerComponent* GripMotionController, const FBPActorGripInformation& GripToDrop, FVector AngleVel, FVector LinearVel);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void DropAllGrips(UGripMotionControllerComponent* GripMotionController, bool bZeroVelo);

};
