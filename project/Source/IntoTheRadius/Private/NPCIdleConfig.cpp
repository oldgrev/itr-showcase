#include "NPCIdleConfig.h"

#include "ITRDefaults.h"
FNPCIdleConfig::FNPCIdleConfig() {
    LookAroundAfterWalk = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("WalkSpeedRange.Min"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("WalkSpeedRange.Max"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleTimeRange.Min"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleTimeRange.Max"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RotationSpeedRange.Min"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RotationSpeedRange.Max"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LookAroundAfterWalk"), true);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AwarenessConfig.AwarenessLowLevel"), (double)8);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AwarenessConfig.AwarenessHighLevel"), (double)20);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AwarenessConfig.AwarenessDecrease"), (double)0.25);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedAwarenessConfig.AwarenessLowLevel"), (double)8);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedAwarenessConfig.AwarenessHighLevel"), (double)20);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedAwarenessConfig.AwarenessDecrease"), (double)0.25);
}

FNPCIdleConfig::~FNPCIdleConfig() {
}
