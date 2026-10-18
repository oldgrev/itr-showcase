#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EDamageCategory.h"
#include "EHandPose.h"
#include "EInventoryMode.h"
#include "EPRHand.h"
#include "EPRHandPoseGeometryType.h"
#include "EPRHandPoseNumber.h"
#include "EPlayerTeleportAdjustType.h"
#include "IPRPlayerCharacter.generated.h"

class AActor;
class UCameraComponent;
class UGripMotionControllerComponent;
class UInventoryItem;
class UMaterialInstanceDynamic;
class UObject;
class UPRItemConfig;
class USceneComponent;
class USkeletalMeshComponent;
class USphereComponent;

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIPRPlayerCharacter : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIPRPlayerCharacter {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UpdateHolders();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void TeleportPlayer(FTransform Transform, FVector Velocity, bool wristMenuHidden, bool ReprojectLocation, EPlayerTeleportAdjustType adjust);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void StopMovement();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void StopHapticses();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SpawnItemInHand(bool LeftHand, FGameplayTag ItemTypeID);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SpawnItemConfigInHand(bool bLeftHand, UPRItemConfig* itemConfig);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SpawnInventory();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetWristMenuHidden(bool Hidden);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetPaused(bool paused);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool SetInventoryMode(EInventoryMode Mode);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetCurrentVelocity(const FVector Velocity);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void ReturnBackpack(bool instant);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void RefreshHandPose(UGripMotionControllerComponent* Controller);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void PreTeleport();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OpenEyes();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnTeleported();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnDominantHandChosen();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    const bool IsTeleporting() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    bool IsItemActorSticked(AActor* Actor);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsImmuneToDamage(const EDamageCategory Type) const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    bool IsActorLerpingToHand(const UObject* Object);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void Initialize();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetTotalEquipmentWeight();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FTransform GetRootTransform() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetPlayerHeightScale() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetPlayerHeight() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetOneHeldItem(EPRHand hand, const bool onlyItem, UObject*& itemActorObject, bool& SecondaryGrip) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    EInventoryMode GetInventoryMode() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetHeldItems(const bool bOnlyItem, UObject*& Left, UObject*& Right) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetHandsIKData(bool& success, bool& alive, FTransform& leftHandTransform, FTransform& leftHandShiftTransform, EHandPose& leftHandPose, EPRHandPoseGeometryType& leftHandGeometryType, EPRHandPoseNumber& leftHandPoseNumber, UObject*& leftHeldItem, FTransform& rightHandTransform, FTransform& rightHandShiftTransform, EHandPose& rightHandPose, EPRHandPoseGeometryType& rightHandGeometryType, EPRHandPoseNumber& rightHandPoseNumber, UObject*& rightHeldItem);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetHandPivot(UGripMotionControllerComponent* Controller, USceneComponent*& Pivot);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetDistanceToCamera(const FVector WorldLocation) const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetCurrentVelocity(FVector& Velocity) const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetControlsRefs(bool& success, bool& alive, UCameraComponent*& cameraRef, USceneComponent*& pivotHead, UGripMotionControllerComponent*& leftControllerRef, USceneComponent*& pivotLeftController, USceneComponent*& pivotLeftHand, USphereComponent*& sphereLeftHand, UMaterialInstanceDynamic*& materialLeftController, UGripMotionControllerComponent*& rightControllerRef, USceneComponent*& pivotRightController, USceneComponent*& pivotRightHand, USphereComponent*& sphereRightHand, UMaterialInstanceDynamic*& materialRightController);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    UCameraComponent* GetCameraRef() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    USkeletalMeshComponent* GetBodyRef() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetBodyIKData(bool& bSuccess, bool& bAlive, FTransform& RootTransform, FTransform& CameraTransform, FTransform& NeckTransform);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetBeamPointerComponents(USceneComponent*& Left, USceneComponent*& Right);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    USceneComponent* GetBackpackPivot();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    TMap<EDamageCategory, float> GetArmorStats() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    TArray<UInventoryItem*> GetArmorItems() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void DropNotItems();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void DropAll();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void CloseEyes();

};
