#include "PRHandPoseConditions.h"

#include "ITRDefaults.h"
FPRHandPoseConditions::FPRHandPoseConditions() {
    MaxDistanceForGrip = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("MaxDistanceForGrip"), (double)200);
}
