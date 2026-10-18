#include "NPCCloseCombatConfig.h"

#include "ITRDefaults.h"
FNPCCloseCombatConfig::FNPCCloseCombatConfig() {
    UseCloseCombatManager = {};
    CloseCombatWeight = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("UseCloseCombatManager"), true);
    ITRDefaults::Set(StaticStruct(), this, TEXT("CloseCombatWeight"), (double)1);
}

FNPCCloseCombatConfig::~FNPCCloseCombatConfig() {
}
