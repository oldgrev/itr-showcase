#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/EngineTypes.h"
#include "EBotMovementMode.h"
#include "EGait.h"
#include "EMovementAction.h"
#include "EMovementState.h"
#include "EOverlayState.h"
#include "ERotationMode.h"
#include "EStance.h"
#include "EViewMode.h"
#include "IALSAnimation.h"
#include "IALSCharacter.h"
#include "MovementSettings.h"
#include "MovementSettingsState.h"
#include "PRCharacter.h"
#include "PRALSCharacter.generated.h"

class UAnimInstance;
class UAnimMontage;
class UParticleSystem;
class USoundBase;

UCLASS(Blueprintable, BlueprintType, Config=Game)
class INTOTHERADIUS_API APRALSCharacter : public APRCharacter, public IIALSAnimation, public IIALSCharacter {
    GENERATED_BODY()
public:
    APRALSCharacter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateGroundedRotation();

    UFUNCTION(BlueprintCallable)
    void UpdateDynamicMovementSettings(EGait AllowedGait);

    UFUNCTION(BlueprintCallable)
    void UpdateCharacterMovement();

    UFUNCTION(BlueprintCallable)
    void SmoothCharacterRotation(FRotator Target, float TargetInterpSpeed, float ActorInterpSpeed);

    UFUNCTION(BlueprintCallable)
    void SetMovementModel();

    UFUNCTION(BlueprintCallable)
    void SetEssentialValues();

    UFUNCTION(BlueprintCallable)
    void SetActorLocationDuringRagdoll();

    UFUNCTION(BlueprintCallable)
    bool SetActorLocationAndRotation(FVector NewLocation, FRotator NewRotation, bool bSweep, bool bTeleport, FHitResult& OutSweepHitResult);

    UFUNCTION(BlueprintCallable)
    void RagdollUpdate();

    UFUNCTION(BlueprintCallable)
    void RagdollStart();

    UFUNCTION(BlueprintCallable)
    void RagdollEnd();

    UFUNCTION(BlueprintCallable)
    void OnViewModeChanged(EViewMode NewViewMode);

    UFUNCTION(BlueprintCallable)
    virtual void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust);

    UFUNCTION(BlueprintCallable)
    void OnStanceChanged(EStance NewStance);

    UFUNCTION(BlueprintCallable)
    void OnRotationModeChanged(ERotationMode NewRotationMode);

    UFUNCTION(BlueprintCallable)
    void OnOverlayStateChanged(EOverlayState NewOverLayState);

    UFUNCTION(BlueprintCallable)
    void OnMovementStateChanged(EMovementState NewMovementState);

    UFUNCTION(BlueprintCallable)
    void OnGaitChanged(EGait NewActualGait);

    UFUNCTION(BlueprintCallable)
    virtual void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust);

    UFUNCTION(BlueprintCallable)
    void OnCharacterMovementModeChanged(TEnumAsByte<EMovementMode> NewMovementMode, uint8 NewCustomMode);

    UFUNCTION(BlueprintCallable)
    void OnCharacterMovementActionChanged(EMovementAction NewMovementAction);

    UFUNCTION(BlueprintCallable)
    void OnBeginPlay();

    UFUNCTION(BlueprintCallable)
    void LimitRotation(float AimYawMin, float AimYawMax, float InterpSpeed);

    UFUNCTION(BlueprintCallable)
    FMovementSettings GetTargetMovementSettings() const;

    UFUNCTION(BlueprintCallable)
    UAnimMontage* GetRollAnimation() const;

    UFUNCTION(BlueprintCallable)
    float GetMappedSpeed() const;

    UFUNCTION(BlueprintCallable)
    UAnimMontage* GetGetUpAnimation(bool bRagDollFaceUp);

    UFUNCTION(BlueprintCallable)
    FVector GetCapsuleLocationFromBase(FVector BaseLocation, float ZOffset) const;

    UFUNCTION(BlueprintCallable)
    FVector GetCapsuleBaseLocation(float ZOffset) const;

    UFUNCTION(BlueprintCallable)
    float GetAnimCurveValue(FName CurveName) const;

    UFUNCTION(BlueprintCallable)
    FRotator GetAimingRotation() const;

    UFUNCTION(BlueprintCallable)
    EGait GetActualGait(EGait AllowedGait) const;

    UFUNCTION(BlueprintCallable)
    bool CanUpdateMovingRotation() const;

    UFUNCTION(BlueprintCallable)
    bool CanSprint() const;

    UFUNCTION(BlueprintCallable)
    float CalculateGroundedRotationRate() const;

    UFUNCTION(BlueprintCallable)
    FVector CalculateAcceleration() const;

    UFUNCTION(BlueprintCallable)
    void CacheValues();

    UFUNCTION(BlueprintCallable)
    virtual void BeginPlay();

    UFUNCTION(BlueprintCallable)
    void AddToCharacterRotation(FRotator DeltaRotation);

    UPROPERTY(BlueprintReadWrite)
    float Speed;
    UPROPERTY(BlueprintReadWrite)
    FVector Acceleration;
    UPROPERTY(BlueprintReadWrite)
    bool IsMoving;
    UPROPERTY(BlueprintReadWrite)
    bool HasMovementInput;
    UPROPERTY(BlueprintReadWrite)
    FRotator LastVelocityRotation;
    UPROPERTY(BlueprintReadWrite)
    FRotator LastMovementInputRotation;
    UPROPERTY(BlueprintReadWrite)
    float MovementInputAmount;
    UPROPERTY(BlueprintReadWrite)
    float AimYawRate;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OptimalShootRange;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EBotMovementMode BotMovementMode;
    UPROPERTY(BlueprintReadWrite)
    FVector PreviousVelocity;
    UPROPERTY(BlueprintReadWrite)
    float PreviousAimYaw;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ERotationMode DesiredRotationMode;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EGait DesiredGait;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EStance DesiredStance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float LookUpDownRate;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float LookLeftRightRate;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 TimesPressedStance;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    bool BreakFall;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    bool SprintHeld;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UAnimInstance* MainAnimInstance;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EMovementState MovementState;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EMovementState PrevMovementState;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ERotationMode RotationMode;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EGait Gait;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EStance Stance;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EOverlayState OverlayState;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EViewMode ViewMode;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FDataTableRowHandle MovementModel;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    FMovementSettingsState MovementData;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FMovementSettings CurrentMovementSettings;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FRotator TargetRotation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float YawOffset;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RagdollOnGround;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RagdollFaceUp;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector LastRagdollVelocity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    USoundBase* DeathSound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UParticleSystem* DeathParticle;
};
