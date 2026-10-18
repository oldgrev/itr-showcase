#include "NPCSightConfig.h"

#include "ITRDefaults.h"
FNPCSightConfig::FNPCSightConfig() {
    AngleLeft = {};
    AngleRight = {};
    AngleUp = {};
    AngleDown = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("DistanceRange.Min"), (double)700);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DistanceRange.Max"), (double)1000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AngleLeft"), (double)45);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AngleRight"), (double)45);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AngleUp"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AngleDown"), (double)30);
}

FNPCSightConfig::~FNPCSightConfig() {
}
