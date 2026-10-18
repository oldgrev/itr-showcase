#include "GripOverlap.h"

#include "ITRDefaults.h"
FGripOverlap::FGripOverlap() {
    Object = {};
    ImplementsInterface = {};
    CanBeClimbed = {};
    OverlapedPrimitive = {};
    IsDistanceGrip = {};
    IsSlotGrip = {};
    TriggerPrimitive = {};
    GeometryType = {};
    PoseNumer = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ObjectTransform.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ObjectTransform.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ObjectTransform.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ObjectTransform.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ObjectTransform.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ObjectTransform.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ObjectTransform.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ObjectTransform.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ObjectTransform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ObjectTransform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("GripPoint.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("GripPoint.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("GripPoint.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("GripPoint.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("GripPoint.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("GripPoint.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("GripPoint.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("GripPoint.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("GripPoint.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("GripPoint.Scale3D.Z"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerPoint.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerPoint.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerPoint.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerPoint.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerPoint.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerPoint.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerPoint.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerPoint.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerPoint.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerPoint.Scale3D.Z"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandTransformWhenOverlap.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandTransformWhenOverlap.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandTransformWhenOverlap.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandTransformWhenOverlap.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandTransformWhenOverlap.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandTransformWhenOverlap.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandTransformWhenOverlap.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandTransformWhenOverlap.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandTransformWhenOverlap.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HandTransformWhenOverlap.Scale3D.Z"), (double)1);
}
