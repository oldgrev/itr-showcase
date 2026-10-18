#include "Parallelepiped.h"

#include "ITRDefaults.h"
FParallelepiped::FParallelepiped() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("Center.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Center.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Center.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Center.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Center.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Center.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Center.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Center.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Center.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Center.Scale3D.Z"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Extent.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Extent.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Extent.Z"), (double)1);
}
