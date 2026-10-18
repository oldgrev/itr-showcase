#pragma once

#include "CoreMinimal.h"
#include "EHandPose.h"
#include "EPRHandPoseGeometryType.h"
#include "EPRHandPoseNumber.h"
#include "PRAnimInstance.h"
#include "PRHandPoseInfo.h"
#include "PRAnimPlayer.generated.h"

class AActor;
class APawn;
class UObject;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRAnimPlayer : public UPRAnimInstance {
    GENERATED_BODY()
public:
    UPRAnimPlayer(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void ReceiveInputDataNative();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    APawn* Pawn;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisable;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform InputLeftHandTransform;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EHandPose InputLeftPose;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPRHandPoseGeometryType InputLeftHandGeometryType;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPRHandPoseNumber InputLeftHandPoseNumber;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRHandPoseInfo InputLeftPoseInfo;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* InputLeftObject;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* InputLeftActor;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform InputRightHandTransform;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EHandPose InputRightPose;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPRHandPoseGeometryType InputRightHandGeometryType;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPRHandPoseNumber InputRightHandPoseNumber;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPRHandPoseInfo InputRightPoseInfo;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* InputRightObject;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* InputRightActor;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InputDirection;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InputSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector InputVelocity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InputPlayerHeight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InputPlayerHeightScale;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform InputRootTransform;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform InputCameraTransform;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform InputNeckTransform;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bInputRagdoll;
    UPROPERTY(BlueprintReadOnly)
    float PlayerMeshHeight;
    UPROPERTY(BlueprintReadOnly)
    float PlayerMeshEyeHeight;
    UPROPERTY(BlueprintReadOnly)
    float NeckOffset;
    UPROPERTY(BlueprintReadOnly)
    float MinPlayerHeight;
    UPROPERTY(BlueprintReadOnly)
    float MaxPlayerHeight;
};
