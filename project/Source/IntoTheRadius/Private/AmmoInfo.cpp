#include "AmmoInfo.h"

#include "ITRDefaults.h"
FAmmoInfo::FAmmoInfo() {
    ShellMesh = {};
    WholeMesh = {};
    ShortInfo = {};
    VelocityMultiplier = {};
    DamageType = {};
    Penetration = {};
    BounceMax = {};
    ArmorPiercing = {};
    DamageModifier = {};
    SpeedDropCurve = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("AmmoCaliberID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("AmmoTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("VelocityMultiplier"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("BounceMax"), (double)2);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DamageModifier"), (double)1);
}

FAmmoInfo::~FAmmoInfo() {
}
