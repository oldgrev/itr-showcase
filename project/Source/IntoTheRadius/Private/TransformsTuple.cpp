#include "TransformsTuple.h"

#include "ITRDefaults.h"
FTransformsTuple::FTransformsTuple() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.Scale3D.Z"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.Scale3D.Z"), (double)1);
}
