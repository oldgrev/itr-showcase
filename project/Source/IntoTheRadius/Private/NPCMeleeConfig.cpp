#include "NPCMeleeConfig.h"

#include "ITRDefaults.h"
FNPCMeleeConfig::FNPCMeleeConfig() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("DistanceRange.Min"), (double)300);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DistanceRange.Max"), (double)300);
}

FNPCMeleeConfig::~FNPCMeleeConfig() {
}
