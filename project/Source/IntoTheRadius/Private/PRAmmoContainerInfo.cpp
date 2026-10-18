#include "PRAmmoContainerInfo.h"

#include "ITRDefaults.h"
FPRAmmoContainerInfo::FPRAmmoContainerInfo() {
    IgnoreChamberCountInInspect = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTypeID.TagName"), TEXT("None"));
}

FPRAmmoContainerInfo::~FPRAmmoContainerInfo() {
}
