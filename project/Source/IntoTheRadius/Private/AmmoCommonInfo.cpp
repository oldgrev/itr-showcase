#include "AmmoCommonInfo.h"

#include "ITRDefaults.h"
FAmmoCommonInfo::FAmmoCommonInfo() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("AmmoType.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("Color.R"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Color.G"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Color.B"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Color.A"), (double)1);
}
