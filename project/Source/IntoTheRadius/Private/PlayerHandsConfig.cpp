#include "PlayerHandsConfig.h"
#include "ITRDefaults.h"

UPlayerHandsConfig::UPlayerHandsConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.PlayerHandsConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.LeftShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.LeftShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.LeftShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.LeftShift.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.LeftShift.Translation.X"), (double)40);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.LeftShift.Translation.Y"), (double)-40);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.LeftShift.Translation.Z"), (double)110);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.LeftShift.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.LeftShift.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.LeftShift.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.RightShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.RightShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.RightShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.RightShift.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.RightShift.Translation.X"), (double)40);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.RightShift.Translation.Y"), (double)40);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.RightShift.Translation.Z"), (double)110);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.RightShift.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.RightShift.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("MotionSourcesDefaultPosition.RightShift.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("PistolsStickBreakDistance"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.PoseTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.HandShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.HandShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.HandShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.HandShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.HandShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.HandShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.PointShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.PointShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.PointShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.PointShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.PointShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.PointShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.SplineShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.SplineShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.SplineShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.SplineShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.SplineShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.SplineShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.HandShiftRelatedSpline.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.HandShiftRelatedSpline.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.HandShiftRelatedSpline.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.HandShiftRelatedSpline.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.HandShiftRelatedSpline.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.SplineData.HandShiftRelatedSpline.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.HandPoseConditions.MaxDistanceForGrip"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerThumbShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerThumbShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerThumbShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerThumbShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerThumbShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerThumbShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerIndexShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerIndexShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerIndexShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerIndexShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerIndexShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerIndexShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerMiddleShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerMiddleShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerMiddleShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerMiddleShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerMiddleShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerMiddleShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerRingShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerRingShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerRingShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerRingShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerRingShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerRingShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerPinkyShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerPinkyShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerPinkyShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerPinkyShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerPinkyShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Left.FingerPinkyShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.HandShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.HandShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.HandShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.HandShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.HandShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.HandShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.PointShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.PointShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.PointShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.PointShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.PointShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.PointShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.SplineShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.SplineShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.SplineShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.SplineShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.SplineShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.SplineShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.HandShiftRelatedSpline.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.HandShiftRelatedSpline.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.HandShiftRelatedSpline.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.HandShiftRelatedSpline.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.HandShiftRelatedSpline.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.SplineData.HandShiftRelatedSpline.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.HandPoseConditions.MaxDistanceForGrip"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerThumbShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerThumbShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerThumbShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerThumbShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerThumbShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerThumbShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerIndexShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerIndexShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerIndexShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerIndexShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerIndexShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerIndexShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerMiddleShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerMiddleShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerMiddleShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerMiddleShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerMiddleShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerMiddleShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerRingShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerRingShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerRingShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerRingShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerRingShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerRingShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerPinkyShift.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerPinkyShift.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerPinkyShift.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerPinkyShift.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerPinkyShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HandsPoseDefault.Right.FingerPinkyShift.Rotation.Z"), (double)0);
}

FTransform UPlayerHandsConfig::ToTransform(FPRCleanTransform cleanTransform) {
    return {};
}

void UPlayerHandsConfig::ShowDeviceModel(USceneComponent* Parent, UPrimitiveComponent* DisplayComponent, EControllerHand hand, UPrimitiveComponent*& newDisplayComponent) {
}

void UPlayerHandsConfig::SaveToAsset() {
}

void UPlayerHandsConfig::SavePoseDefault(TMap<EPRControllerType, FPRCleanTransform> leftItemShifts, TMap<EPRControllerType, FPRCleanTransform> rightItemShifts, FPRHandPoseInfosPair handsData) {
}

bool UPlayerHandsConfig::HaveHandsPoseForTagByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, FGameplayTag Tag, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber) const {
    return {};
}

bool UPlayerHandsConfig::HaveHandsPoseForTag(const EPRHandPoseType PoseType, const FGameplayTag Tag) const {
    return {};
}

bool UPlayerHandsConfig::HaveHandsPoseForStaticMeshByGeometryTypeAndPoseNumber(const EPRHandPoseType PoseType, UStaticMesh* StaticMesh, const EPRHandPoseGeometryType GeometryType, const EPRHandPoseNumber PoseNumber) const {
    return {};
}

bool UPlayerHandsConfig::HaveHandsPoseForStaticMesh(const EPRHandPoseType PoseType, UStaticMesh* StaticMesh) const {
    return {};
}

bool UPlayerHandsConfig::HaveHandsPoseForObjectByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, UObject* Object, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber) const {
    return {};
}

bool UPlayerHandsConfig::HaveHandsPoseForObject(EPRHandPoseType PoseType, UObject* Object) const {
    return {};
}

FTransform UPlayerHandsConfig::GetShiftForController(const FPRHandPoseInfo& Info, const EPRControllerType& Controller) {
    return {};
}

void UPlayerHandsConfig::GetPointShiftForObjectByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform, FPRHandPoseConditions& HandPoseConditions) const {
}

void UPlayerHandsConfig::GetPointShiftForObject(EPRHandPoseType PoseType, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform) const {
}

UPlayerHandsConfig* UPlayerHandsConfig::GetPlayerHandsConfig() {
    return {};
}

void UPlayerHandsConfig::GetItemShiftForController(const TMap<EPRControllerType, FTransform>& shiftPerController, const EPRControllerType& Controller, FTransform& Shift) {
}

FPRHandPoseInfosPair UPlayerHandsConfig::GetHandsPoseForTagByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, FGameplayTag Tag, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber) const {
    return {};
}

FPRHandPoseInfosPair UPlayerHandsConfig::GetHandsPoseForTag(EPRHandPoseType PoseType, FGameplayTag Tag) const {
    return {};
}

FPRHandPoseInfosPair UPlayerHandsConfig::GetHandsPoseForStaticMeshByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, UStaticMesh* StaticMesh, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber) const {
    return {};
}

FPRHandPoseInfosPair UPlayerHandsConfig::GetHandsPoseForStaticMesh(EPRHandPoseType PoseType, UStaticMesh* StaticMesh) const {
    return {};
}

FPRHandPoseInfosPair UPlayerHandsConfig::GetHandsPoseForObjectByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, UObject* Object, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber) const {
    return {};
}

FPRHandPoseInfosPair UPlayerHandsConfig::GetHandsPoseForObject(EPRHandPoseType PoseType, UObject* Object) const {
    return {};
}

void UPlayerHandsConfig::GetHandShiftForObjectByGeometryTypeAndPoseNumber(EPRHandPoseType PoseType, EPRHandPoseGeometryType GeometryType, EPRHandPoseNumber PoseNumber, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform, FPRHandPoseConditions& HandPoseConditions) const {
}

void UPlayerHandsConfig::GetHandShiftForObject(EPRHandPoseType PoseType, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform) const {
}

void UPlayerHandsConfig::GetControllerShifts(const EPRControllerType Controller, FTransform& LeftShift, FTransform& RightShift) {
}

void UPlayerHandsConfig::GetBestPointShiftForObjectByConditions(EPRHandPoseType PoseType, UObject* Object, bool Left, const FTransform& handTransform, bool useGripLimit, const FVector& handRootLocation, const UGripMotionControllerComponent* MotionController, bool& success, FTransform& Result, FTransform& WorldTransform, EPRHandPoseGeometryType& bestGeometryType, EPRHandPoseNumber& bestPoseNumber) const {
}

void UPlayerHandsConfig::GetBestPointShiftForObject(EPRHandPoseType PoseType, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform, EPRHandPoseGeometryType& bestGeometryType, EPRHandPoseNumber& bestPoseNumber) const {
}

void UPlayerHandsConfig::GetBestHandShiftForObjectByConditions(EPRHandPoseType PoseType, UObject* Object, bool bLeft, const FTransform& CurrentHandTransform, bool bUseArmLengthLimit, const FVector& HandShoulderLocation, const UGripMotionControllerComponent* MotionController, bool& bSuccess, FTransform& PoseRelativeTransform, FTransform& PoseWorldTransform, EPRHandPoseGeometryType& PoseGeometryType, EPRHandPoseNumber& PoseNumber) const {
}

void UPlayerHandsConfig::GetBestHandShiftForObject(EPRHandPoseType PoseType, UObject* Object, bool Left, const FTransform& handTransform, bool& success, FTransform& Result, FTransform& WorldTransform, EPRHandPoseGeometryType& bestGeometryType, EPRHandPoseNumber& bestPoseNumber) const {
}

FPRCleanTransform UPlayerHandsConfig::FromTransform(FTransform Transform) {
    return {};
}

