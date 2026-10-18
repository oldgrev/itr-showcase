#include "ShiftsPair.h"

#include "ITRDefaults.h"
FShiftsPair::FShiftsPair() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeftShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeftShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeftShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeftShift.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeftShift.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeftShift.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeftShift.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeftShift.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeftShift.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeftShift.Scale3D.Z"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RightShift.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RightShift.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RightShift.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RightShift.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RightShift.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RightShift.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RightShift.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RightShift.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RightShift.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RightShift.Scale3D.Z"), (double)1);
}
