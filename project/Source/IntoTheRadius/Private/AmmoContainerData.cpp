#include "AmmoContainerData.h"

#include "ITRDefaults.h"
FAmmoContainerData::FAmmoContainerData() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("ChamberAmmo.TagName"), TEXT("None"));
}

FAmmoContainerData::~FAmmoContainerData() {
}
