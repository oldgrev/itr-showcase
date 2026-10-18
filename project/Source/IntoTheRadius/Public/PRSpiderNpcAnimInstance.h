#pragma once

#include "CoreMinimal.h"
#include "PRAnimInstance.h"
#include "PRSpiderNpcAnimInstance.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRSpiderNpcAnimInstance : public UPRAnimInstance {
    GENERATED_BODY()
public:
    UPRSpiderNpcAnimInstance(const FObjectInitializer& ObjectInitializer);

protected:
    UPROPERTY(EditDefaultsOnly)
    FVector Velocity;
    UPROPERTY(EditDefaultsOnly)
    float RootSpinInDegPerSec;
    UPROPERTY(EditDefaultsOnly)
    float IdleLegBendInDeg;
    UPROPERTY(EditDefaultsOnly)
    float IdleBendPercentAtLegRoot;
    UPROPERTY(EditDefaultsOnly)
    float MovingLegBendInDeg;
    UPROPERTY(EditDefaultsOnly)
    float MovingBendPercentAtLegRoot;
    UPROPERTY(EditDefaultsOnly)
    float BendDeltaInDegPerSec;
    UPROPERTY(EditDefaultsOnly)
    bool bJitterEnabled;
    UPROPERTY(EditDefaultsOnly)
    float IdleJitterLerpCycleInSec;
    UPROPERTY(EditDefaultsOnly)
    float IdleJitterRadius;
    UPROPERTY(EditDefaultsOnly)
    float MovingJitterLerpCycleInSec;
    UPROPERTY(EditDefaultsOnly)
    float MovingJitterRadius;
    UPROPERTY(EditDefaultsOnly)
    bool bVelocityDragEnabled;
    UPROPERTY(EditDefaultsOnly)
    float VelocityDragFactor;
    UPROPERTY(EditDefaultsOnly)
    float HighVelocityDragFactor;
    UPROPERTY(EditDefaultsOnly)
    float HighVelocityThreshold;
    UPROPERTY(EditDefaultsOnly)
    float DragDeltaPerSec;
    UPROPERTY(BlueprintReadOnly)
    FRotator SkeletonRootRotation;
    UPROPERTY(BlueprintReadOnly)
    FRotator Leg1Rotation;
    UPROPERTY(BlueprintReadOnly)
    FVector Leg1Displacement;
    UPROPERTY(BlueprintReadOnly)
    FRotator Leg2Rotation;
    UPROPERTY(BlueprintReadOnly)
    FVector Leg2Displacement;
    UPROPERTY(BlueprintReadOnly)
    FRotator Leg3Rotation;
    UPROPERTY(BlueprintReadOnly)
    FVector Leg3Displacement;
    UPROPERTY(BlueprintReadOnly)
    FRotator Leg4Rotation;
    UPROPERTY(BlueprintReadOnly)
    FVector Leg4Displacement;
    UPROPERTY(BlueprintReadOnly)
    FRotator Leg5Rotation;
    UPROPERTY(BlueprintReadOnly)
    FVector Leg5Displacement;
    UPROPERTY(BlueprintReadOnly)
    FRotator Leg6Rotation;
    UPROPERTY(BlueprintReadOnly)
    FVector Leg6Displacement;
    UPROPERTY(BlueprintReadOnly)
    FRotator Leg7Rotation;
    UPROPERTY(BlueprintReadOnly)
    FVector Leg7Displacement;
    UPROPERTY(BlueprintReadOnly)
    FRotator Leg8Rotation;
    UPROPERTY(BlueprintReadOnly)
    FVector Leg8Displacement;
};
