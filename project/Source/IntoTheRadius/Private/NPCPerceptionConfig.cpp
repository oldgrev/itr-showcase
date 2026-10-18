#include "NPCPerceptionConfig.h"

#include "ITRDefaults.h"
FNPCPerceptionConfig::FNPCPerceptionConfig() {
    SenseSightNightModifier = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseHearingRadiusRange.Min"), (double)300);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseHearingRadiusRange.Max"), (double)500);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseNearRadiusRange.Min"), (double)50);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseNearRadiusRange.Max"), (double)200);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseSightConfig.DistanceRange.Min"), (double)700);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseSightConfig.DistanceRange.Max"), (double)1000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseSightConfig.AngleLeft"), (double)45);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseSightConfig.AngleRight"), (double)45);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseSightConfig.AngleUp"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseSightConfig.AngleDown"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SensesTickTimeRange.Min"), (double)0.0500000007);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SensesTickTimeRange.Max"), (double)0.200000003);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SenseSightNightModifier"), (double)0.400000006);
}

FNPCPerceptionConfig::~FNPCPerceptionConfig() {
}
