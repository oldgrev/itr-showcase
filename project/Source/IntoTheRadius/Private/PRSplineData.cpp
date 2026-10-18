#include "PRSplineData.h"

#include "ITRDefaults.h"
FPRSplineData::FPRSplineData() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineShift.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineShift.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineShift.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SplineShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShiftRelatedSpline.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShiftRelatedSpline.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShiftRelatedSpline.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShiftRelatedSpline.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShiftRelatedSpline.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandShiftRelatedSpline.Rotation.Z"), (double)0);
}

FPRSplineData::~FPRSplineData() {
}
