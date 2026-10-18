#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "VRCharacter.h"
#include "EDamageCategory.h"
#include "EHandPose.h"
#include "EHapticsCurve.h"
#include "EInventoryMode.h"
#include "EPRHandPoseGeometryType.h"
#include "EPRHandPoseNumber.h"
#include "EPRHandPoseType.h"
#include "ESpeedCoefficient.h"
#include "GripOverlap.h"
#include "IHealthStatus.h"
#include "IPRPlayerCharacter.h"
#include "PRPlayerControlsInterface.h"
#include "PRPlayerPawn.h"
#include "PRPlayerCharacter.generated.h"

class AActor;
class ABackpackSimple;
class APRHolderMark;
class UBoxComponent;
class UCapsuleComponent;
class UChildActorComponent;
class UGripMotionControllerComponent;
class UHolsterComponent;
class UObject;
class UPRPlayerGripSystemComponent;
class UPRPlayerVisibilityComponent;
class UParticleSystemComponent;
class UPlayerStatsComponent;
class UPrimitiveComponent;
class URadiusAutomationComponent;
class URadiusPlayerMovementComponent;
class USceneComponent;
class USkeletalMeshComponent;
class USoundAttenuation;
class USoundBase;
class USphereComponent;
class UStaticMeshComponent;
class UVRControllerComponent;
class UWidgetComponent;
class UWidgetInteractionComponent;

UCLASS(Blueprintable, BlueprintType, Config=Game)
class INTOTHERADIUS_API APRPlayerCharacter : public AVRCharacter, public IIPRPlayerCharacter, public IIHealthStatus, public IPRPlayerPawn, public IPRPlayerControlsInterface {
    GENERATED_BODY()
public:
    APRPlayerCharacter(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UpdateItemInfos();

    UFUNCTION(BlueprintCallable)
    void UpdateIndicatorsVisibility_Native();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UnbindInteractable(const AActor* Actor) const;

    UFUNCTION(BlueprintCallable)
    bool TryToGrabObject_Native(UObject* ObjectToTryToGrab, const FTransform& WorldTransform, UGripMotionControllerComponent* CallingHand, UGripMotionControllerComponent* OtherHand, bool bIsSlotGrip, EControllerHand EnumHand, bool bIsDistanceGrip);

    UFUNCTION(BlueprintCallable)
    void TryDropSimulating_Native(UGripMotionControllerComponent* hand);

    UFUNCTION(BlueprintCallable)
    void TakeInHand_Native(UGripMotionControllerComponent* hand, UObject* Object, bool bIsCallerHandLeft);

    UFUNCTION(BlueprintCallable)
    void RecreateBackpack_Native();

    UFUNCTION(BlueprintCallable)
    void ProcessDamageArmor(const float Damage, const EDamageCategory DamageCategory, AActor* causer, float& ResultDamage);

    UFUNCTION(BlueprintCallable)
    void PositionClimbingIndicatorNative(bool bIsLeftHand, bool bReset);

    UFUNCTION(BlueprintCallable)
    void OverlapsUINative(const UPrimitiveComponent* Prim, bool bLeft, bool& bOverlaps) const;

    UFUNCTION(BlueprintCallable)
    void OverlapGripNative(bool bLeft);

    UFUNCTION(BlueprintImplementableEvent)
    void OnInventoryModeChanged(const EInventoryMode Mode);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void LerpRightGrip(AActor* Actor, UGripMotionControllerComponent* hand, bool bIsSlot, FTransform Offset, bool bDisableCollision, bool bKeepHandSnapped);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void LerpLeftGrip(AActor* Actor, UGripMotionControllerComponent* hand, bool bIsSlot, FTransform Offset, bool bDisableCollision, bool bKeepHandSnapped);

    UFUNCTION(BlueprintPure)
    void IsCrouch(bool& bCrouch);

public:
    UFUNCTION(BlueprintCallable)
    bool IsAliveNative();

protected:
    UFUNCTION(BlueprintCallable)
    void InitClimbing_Native(UGripMotionControllerComponent* hand, UObject* Object, bool isObjectRelative);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void HandHaptics(EHapticsCurve Type, EControllerHand hand);

    UFUNCTION(BlueprintCallable)
    bool GripOrDropObject_Native(UGripMotionControllerComponent* CallingHand, UGripMotionControllerComponent* OtherHand);

    UFUNCTION(BlueprintCallable)
    void GripOrDrop_Native(UGripMotionControllerComponent* CallingHand, UGripMotionControllerComponent* OtherHand, const bool bIsGrip, const USphereComponent* GrabSphere);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UWidgetInteractionComponent* GetWidgetInteractionRight() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UWidgetInteractionComponent* GetWidgetInteractionLeft() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UWidgetComponent* GetW_R_WristMenu() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UWidgetComponent* GetW_L_WristMenu() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UCapsuleComponent* GetUIPoseTriggerRight() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UCapsuleComponent* GetUIPoseTriggerLeft() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UBoxComponent* GetTriggerWeaponSecondary() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UBoxComponent* GetTriggerWeaponPrimary() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UBoxComponent* GetTriggerMelee() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UBoxComponent* GetTriggerMap() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UBoxComponent* GetTriggerDetector() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UBoxComponent* GetTriggerBackpack() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UStaticMeshComponent* GetSM_ClimbingIndicatorRight() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UStaticMeshComponent* GetSM_ClimbingIndicatorLeft() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    USphereComponent* GetRHandCollider() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UParticleSystemComponent* GetPS_BeamPointerRight() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UParticleSystemComponent* GetPS_BeamPointerLeft() const;

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    const USceneComponent* GetPivotVest() const;

protected:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    USceneComponent* GetPivotNeck() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    USceneComponent* GetPivotBackpack() const;

    UFUNCTION(BlueprintCallable)
    void GetNearestOverlapObjectNative(USphereComponent* OverlapComponent, UGripMotionControllerComponent* hand, UGripMotionControllerComponent* OtherHand, UObject*& OutNearestObject, bool& bOutImplementsInterface, FTransform& OutObjectTransform, bool& bOutCanBeClimbed, UPrimitiveComponent*& OutPrimitive, bool& bOutIsDistanceGrip, FTransform& OutGripPoint, bool& bOutIsSlotGrip, UPrimitiveComponent*& OutTriggerPrimitive, FTransform& OutTriggerTransform, bool& bOutSecondary, FTransform& OutHandTransformWhenOverlap, EPRHandPoseGeometryType& OutGeometryType, EPRHandPoseNumber& OutPoseNumber);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    USphereComponent* GetLHandCollider() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    bool GetIsInteractableHolsterable(AActor* Actor) const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UHolsterComponent* GetHolsterWeaponSecondary() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UHolsterComponent* GetHolsterWeaponPrimary() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UHolsterComponent* GetHolsterProbes_R() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UHolsterComponent* GetHolsterProbes_L() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UHolsterComponent* GetHolsterMelee() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UHolsterComponent* GetHolsterMap() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UHolsterComponent* GetHolsterDetector() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UChildActorComponent* GetHolderSmallPouchActorComponent() const;

    UFUNCTION(BlueprintCallable)
    void GetHandDataNative(bool bLeftHand, FTransform& ControllerTransform, FTransform& HandWorldTransform, FTransform& HandShiftTransform, UObject*& Object, bool& SecondaryGrip, EPRHandPoseGeometryType& HandPoseGeometryType, EPRHandPoseNumber& HandPoseNumber);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetGripRelativeTransformByGeometryTypeAndPoseNumber(UObject* GripObject, UGripMotionControllerComponent* HandController, EPRHandPoseType PoseType, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber, bool& bSuccess, FTransform& GripRelativeTransform) const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    USphereComponent* GetGrabSphereRight() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    USphereComponent* GetGrabSphereLeft() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UVRControllerComponent* GetBPC_VRController_Right() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    UVRControllerComponent* GetBPC_VRController_Left() const;

    UFUNCTION(BlueprintCallable)
    bool DropOrRetakeOrHolster_Native(UGripMotionControllerComponent* CallingHand, UObject* ObjectToGrip, const bool bSecondaryGrip, const bool bZeroVelocity);

    UFUNCTION(BlueprintCallable)
    bool DropOrHolster_Native(UGripMotionControllerComponent* CallingHand, UObject* ObjectToGrip, const bool bSecondaryGrip);

public:
    UFUNCTION(BlueprintCallable)
    bool DoesPlayerHolsterPreventInteraction(const AActor* Interactable);

protected:
    UFUNCTION(BlueprintCallable)
    void ClearClimbing_Native(const bool bBecauseOfStepUp);

    UFUNCTION(BlueprintCallable)
    bool CheckTriggerOverlaps_Native(const USphereComponent* GrabSphere, UGripMotionControllerComponent* CallingHand);

    UFUNCTION(BlueprintCallable)
    void CheckHolster_Native(UObject* Object, const bool bRemove, const bool bIsLeftHand, bool& bHolsterFound, bool& bHolsterOk, UHolsterComponent*& Holster);

    UFUNCTION(BlueprintImplementableEvent)
    void CallNightGlow(UObject* Target, bool bOn);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void BindInteractable(const AActor* Actor) const;

    UFUNCTION(BlueprintCallable)
    void BeamPointerToggleNative(bool bOnOff, FVector TargetPoint, bool bIsLeftHand, bool bUIGrip);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    USkeletalMeshComponent* SKBody;
public:
    UPROPERTY(EditAnywhere)
    bool bSweepTeleport;
    UPROPERTY()
    UPRPlayerVisibilityComponent* BpVisibilityComp;
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStatePaused;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsCrouchToggled;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UPRPlayerGripSystemComponent* GripSystemComp;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    URadiusAutomationComponent* AutomationComp;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    URadiusPlayerMovementComponent* RadiusPlayerMovementComponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<ESpeedCoefficient, float> MoveSpeedMult;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector MovementVector;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ForwardBackwardAxis;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DPadVelocityScaler;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RightLeftAxis;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsHandClimbing;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool LThumbPressed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpeedAlpha;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TotalEquipmentWeight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Sprinting;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RightTriggerAngle;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LeftTriggerAngle;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TriggerUnlockThreshold;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TriggerPressThreshold;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDeathTriggered;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGripOverlap OverlapGripRight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGripOverlap OverlapGripLeft;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGripOverlap SelectedGripTargetRight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGripOverlap SelectedGripTargetLeft;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EHandPose HandPoseRight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EHandPose HandPoseLeft;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RUIPressed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool LUIPressed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RGripPressed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool LGripPressed;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float BackpackTriggerDistance;
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ABackpackSimple> BP_BackpackSimpleClass;
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<APRHolderMark> BP_HolderMarkClass;
    UPROPERTY(EditDefaultsOnly)
    USoundBase* ClimbStartSound;
    UPROPERTY(EditDefaultsOnly)
    USoundAttenuation* ClimbStartSoundAttenuation;
    UPROPERTY(EditDefaultsOnly)
    USoundBase* GrabSound;
    UPROPERTY(EditDefaultsOnly)
    USoundAttenuation* GrabSoundAttenuation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ABackpackSimple* backpack;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* SelectorsController;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* ObjectInRightHand;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* ObjectInLeftHand;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RightHandFakeSecondary;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool LeftHandFakeSecondary;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RightHandStick;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool LeftHandStick;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UGripMotionControllerComponent* ClimbingHand;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector ClimbGripLocation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsObjectRelative;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UPrimitiveComponent* ClimbGripObject;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* GripMover;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsFocused;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector DistanceGripPoint_R;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector DistanceGripPoint_L;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    USceneComponent* SecondaryGripingController;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* LeftLastHaptic;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* RightLastHaptic;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* TriggerGripRight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* TriggerGripLeft;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<UHolsterComponent*, APRHolderMark*> HolsterMarks;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bZeroVel;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bBodyVisibilityFlag;
    UPROPERTY(BlueprintReadOnly)
    float PlayerMeshEyeHeight;
    UPROPERTY(BlueprintReadOnly)
    float NeckOffset;
    UPROPERTY(BlueprintReadOnly)
    float PlayerMeshHeight;
    UPROPERTY(BlueprintReadOnly)
    float MinPlayerHeight;
    UPROPERTY(BlueprintReadOnly)
    float MaxPlayerHeight;
private:
    UPROPERTY()
    UPlayerStatsComponent* PlayerStatsComponent;
};
