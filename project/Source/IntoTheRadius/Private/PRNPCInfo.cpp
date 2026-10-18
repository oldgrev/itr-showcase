#include "PRNPCInfo.h"

#include "ITRDefaults.h"
FPRNPCInfo::FPRNPCInfo() {
    ActorClass = {};
    LootPossibilityPercent = {};
    IsArmored = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("NPCConfigID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("MaxHealthRange.Min"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MaxHealthRange.Max"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.WalkSpeedRange.Min"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.WalkSpeedRange.Max"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.IdleTimeRange.Min"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.IdleTimeRange.Max"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.RotationSpeedRange.Min"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.RotationSpeedRange.Max"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.LookAroundAfterWalk"), true);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.AwarenessConfig.AwarenessLowLevel"), (double)8);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.AwarenessConfig.AwarenessHighLevel"), (double)20);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.AwarenessConfig.AwarenessDecrease"), (double)0.25);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.ReducedAwarenessConfig.AwarenessLowLevel"), (double)8);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.ReducedAwarenessConfig.AwarenessHighLevel"), (double)20);
    ITRDefaults::Set(StaticStruct(), this, TEXT("IdleConfig.ReducedAwarenessConfig.AwarenessDecrease"), (double)0.25);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseHearingRadiusRange.Min"), (double)300);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseHearingRadiusRange.Max"), (double)500);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseNearRadiusRange.Min"), (double)50);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseNearRadiusRange.Max"), (double)200);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseSightConfig.DistanceRange.Min"), (double)700);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseSightConfig.DistanceRange.Max"), (double)1000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseSightConfig.AngleLeft"), (double)45);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseSightConfig.AngleRight"), (double)45);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseSightConfig.AngleUp"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseSightConfig.AngleDown"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SensesTickTimeRange.Min"), (double)0.0500000007);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SensesTickTimeRange.Max"), (double)0.200000003);
    ITRDefaults::Set(StaticStruct(), this, TEXT("PerceptionConfig.SenseSightNightModifier"), (double)0.400000006);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseHearingRadiusRange.Min"), (double)300);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseHearingRadiusRange.Max"), (double)500);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseNearRadiusRange.Min"), (double)50);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseNearRadiusRange.Max"), (double)200);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseSightConfig.DistanceRange.Min"), (double)700);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseSightConfig.DistanceRange.Max"), (double)1000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseSightConfig.AngleLeft"), (double)45);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseSightConfig.AngleRight"), (double)45);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseSightConfig.AngleUp"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseSightConfig.AngleDown"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SensesTickTimeRange.Min"), (double)0.0500000007);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SensesTickTimeRange.Max"), (double)0.200000003);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ReducedPerceptionConfig.SenseSightNightModifier"), (double)0.400000006);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MeleeConfig.DistanceRange.Min"), (double)300);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MeleeConfig.DistanceRange.Max"), (double)300);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AttackMoveDilationAngle.Min"), (double)10);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AttackMoveDilationAngle.Max"), (double)15);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LootPossibilityPercent"), (double)50);
    ITRDefaults::Set(StaticStruct(), this, TEXT("CoreItemTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("FootstepNoiseRange.Min"), (double)1000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("FootstepNoiseRange.Max"), (double)1000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("CloseCombatConfig.UseCloseCombatManager"), true);
    ITRDefaults::Set(StaticStruct(), this, TEXT("CloseCombatConfig.CloseCombatWeight"), (double)1);
}

FPRNPCInfo::~FPRNPCInfo() {
}
