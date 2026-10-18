#include "EnemySenseMultiplier.h"

#include "ITRDefaults.h"
FEnemySenseMultiplier::FEnemySenseMultiplier() {
    HearingRadiusRange = {};
    SightDistanceRange = {};
    SightAnglesHorizontal = {};
    SightAnglesVertical = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("HearingRadiusRange"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SightDistanceRange"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SightAnglesHorizontal"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SightAnglesVertical"), (double)1);
}
