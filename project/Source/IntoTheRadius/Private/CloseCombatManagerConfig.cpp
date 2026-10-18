#include "CloseCombatManagerConfig.h"

#include "ITRDefaults.h"
FCloseCombatManagerConfig::FCloseCombatManagerConfig() {
    bEnabled = {};
    CloseRangeRadius = {};
    CircleOfInterestRadius = {};
    MinDistanceFromPlayerToReappear = {};
    TeleportSearchRadius = {};
    Budget = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("bEnabled"), true);
    ITRDefaults::Set(StaticStruct(), this, TEXT("CloseRangeRadius"), (double)2000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("CircleOfInterestRadius"), (double)15000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MinDistanceFromPlayerToReappear"), (double)4000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TeleportSearchRadius"), (double)4000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Budget"), (double)4);
}

FCloseCombatManagerConfig::~FCloseCombatManagerConfig() {
}
