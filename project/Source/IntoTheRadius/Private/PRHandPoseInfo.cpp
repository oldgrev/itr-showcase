#include "PRHandPoseInfo.h"

#include "ITRDefaults.h"
FPRHandPoseInfo::FPRHandPoseInfo() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShift.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShift.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShift.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PointShift.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PointShift.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PointShift.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PointShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PointShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PointShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.SplineShift.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.SplineShift.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.SplineShift.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.SplineShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.SplineShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.SplineShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.HandShiftRelatedSpline.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.HandShiftRelatedSpline.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.HandShiftRelatedSpline.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.HandShiftRelatedSpline.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.HandShiftRelatedSpline.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineData.HandShiftRelatedSpline.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandPoseConditions.MaxDistanceForGrip"), (double)200);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerThumbShift.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerThumbShift.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerThumbShift.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerThumbShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerThumbShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerThumbShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerIndexShift.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerIndexShift.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerIndexShift.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerIndexShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerIndexShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerIndexShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerMiddleShift.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerMiddleShift.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerMiddleShift.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerMiddleShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerMiddleShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerMiddleShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerRingShift.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerRingShift.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerRingShift.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerRingShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerRingShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerRingShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerPinkyShift.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerPinkyShift.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerPinkyShift.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerPinkyShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerPinkyShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FingerPinkyShift.Rotation.Z"), (double)0);
}

FPRHandPoseInfo::~FPRHandPoseInfo() {
}
