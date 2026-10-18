#include "NPCAwarenessConfig.h"

#include "ITRDefaults.h"
FNPCAwarenessConfig::FNPCAwarenessConfig() {
    AwarenessLowLevel = {};
    AwarenessHighLevel = {};
    AwarenessDecrease = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("AwarenessLowLevel"), (double)8);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AwarenessHighLevel"), (double)20);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AwarenessDecrease"), (double)0.25);
}

FNPCAwarenessConfig::~FNPCAwarenessConfig() {
}
