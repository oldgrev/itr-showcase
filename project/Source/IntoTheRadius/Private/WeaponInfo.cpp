#include "WeaponInfo.h"

#include "ITRDefaults.h"
FWeaponInfo::FWeaponInfo() {
    UseVirtualStock = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParameters.RecoilLocationOffset.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParameters.RecoilLocationOffset.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParameters.RecoilLocationOffset.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParameters.StabilizedRecoilLocationOffset.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParameters.StabilizedRecoilLocationOffset.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilParameters.StabilizedRecoilLocationOffset.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("WeaponParameters.TwoHandSmoothingDistance"), (double)50);
    ITRDefaults::Set(StaticStruct(), this, TEXT("WeaponParameters.BurstModeCount"), (double)3);
}

FWeaponInfo::~FWeaponInfo() {
}
