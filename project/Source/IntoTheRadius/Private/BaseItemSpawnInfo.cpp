#include "BaseItemSpawnInfo.h"

#include "ITRDefaults.h"
FBaseItemSpawnInfo::FBaseItemSpawnInfo() {
    Preconfigured = {};
    NotUnique = {};
    CustomDurabilityRatio = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Rotation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Rotation.W"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Translation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Translation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Translation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Scale3D.X"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Transform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Preconfigured"), true);
    ITRDefaults::Set(StaticStruct(), this, TEXT("CustomDurabilityRatio"), (double)1);
}

FBaseItemSpawnInfo::~FBaseItemSpawnInfo() {
}
