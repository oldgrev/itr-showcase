#include "HostileDescription.h"

#include "ITRDefaults.h"
FHostileDescription::FHostileDescription() {
    Group = {};
    Image = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Group"), (double)3);
}

FHostileDescription::~FHostileDescription() {
}
