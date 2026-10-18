#include "PRNpcPerceptionComponent.h"
#include "ITRDefaults.h"

UPRNpcPerceptionComponent::UPRNpcPerceptionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickGroup"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bStartWithTickEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryComponentTick.TickInterval"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PoiActorClass"), TEXT("/Script/IntoTheRadius.PRPointOfInterest"));
    ITRDefaults::Set(GetClass(), this, TEXT("SenseDurationSpottedThreshold"), (double)1.5);
    ITRDefaults::Set(GetClass(), this, TEXT("SenseDurationLostThreshold"), (double)-2);
    ITRDefaults::Set(GetClass(), this, TEXT("bForgetDead"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("bPoiFollowSelection"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("DebugHeight"), (double)160);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseHearingRadiusRange.Min"), (double)300);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseHearingRadiusRange.Max"), (double)500);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseNearRadiusRange.Min"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseNearRadiusRange.Max"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseSightConfig.DistanceRange.Min"), (double)700);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseSightConfig.DistanceRange.Max"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseSightConfig.AngleLeft"), (double)45);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseSightConfig.AngleRight"), (double)45);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseSightConfig.AngleUp"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseSightConfig.AngleDown"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SensesTickTimeRange.Min"), (double)0.0500000007);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SensesTickTimeRange.Max"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("PerceptionConfig.SenseSightNightModifier"), (double)0.400000006);
    ITRDefaults::Set(GetClass(), this, TEXT("AwarenessConfig.AwarenessLowLevel"), (double)8);
    ITRDefaults::Set(GetClass(), this, TEXT("AwarenessConfig.AwarenessHighLevel"), (double)20);
    ITRDefaults::Set(GetClass(), this, TEXT("AwarenessConfig.AwarenessDecrease"), (double)0.25);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCConfigID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.NPCConfigID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.MaxHealthRange.Min"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.MaxHealthRange.Max"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.WalkSpeedRange.Min"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.WalkSpeedRange.Max"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.IdleTimeRange.Min"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.IdleTimeRange.Max"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.RotationSpeedRange.Min"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.RotationSpeedRange.Max"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.LookAroundAfterWalk"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.AwarenessConfig.AwarenessLowLevel"), (double)8);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.AwarenessConfig.AwarenessHighLevel"), (double)20);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.AwarenessConfig.AwarenessDecrease"), (double)0.25);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.ReducedAwarenessConfig.AwarenessLowLevel"), (double)8);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.ReducedAwarenessConfig.AwarenessHighLevel"), (double)20);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.IdleConfig.ReducedAwarenessConfig.AwarenessDecrease"), (double)0.25);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseHearingRadiusRange.Min"), (double)300);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseHearingRadiusRange.Max"), (double)500);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseNearRadiusRange.Min"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseNearRadiusRange.Max"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseSightConfig.DistanceRange.Min"), (double)700);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseSightConfig.DistanceRange.Max"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseSightConfig.AngleLeft"), (double)45);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseSightConfig.AngleRight"), (double)45);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseSightConfig.AngleUp"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseSightConfig.AngleDown"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SensesTickTimeRange.Min"), (double)0.0500000007);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SensesTickTimeRange.Max"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.PerceptionConfig.SenseSightNightModifier"), (double)0.400000006);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseHearingRadiusRange.Min"), (double)300);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseHearingRadiusRange.Max"), (double)500);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseNearRadiusRange.Min"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseNearRadiusRange.Max"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseSightConfig.DistanceRange.Min"), (double)700);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseSightConfig.DistanceRange.Max"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseSightConfig.AngleLeft"), (double)45);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseSightConfig.AngleRight"), (double)45);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseSightConfig.AngleUp"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseSightConfig.AngleDown"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SensesTickTimeRange.Min"), (double)0.0500000007);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SensesTickTimeRange.Max"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.ReducedPerceptionConfig.SenseSightNightModifier"), (double)0.400000006);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.MeleeConfig.DistanceRange.Min"), (double)300);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.MeleeConfig.DistanceRange.Max"), (double)300);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.AttackMoveDilationAngle.Min"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.AttackMoveDilationAngle.Max"), (double)15);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.LootPossibilityPercent"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.CoreItemTypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.FootstepNoiseRange.Min"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.FootstepNoiseRange.Max"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.CloseCombatConfig.UseCloseCombatManager"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("NpcInfo.CloseCombatConfig.CloseCombatWeight"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SenseTickTime"), (double)0.100000001);
    ITRDefaults::Set(GetClass(), this, TEXT("SightSenseRadius"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("SightSenseNightModifier"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SightSenseAngleLeft"), (double)45);
    ITRDefaults::Set(GetClass(), this, TEXT("SightSenseAngleRight"), (double)45);
    ITRDefaults::Set(GetClass(), this, TEXT("SightSenseAngleUp"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("SightSenseAngleDown"), (double)15);
    ITRDefaults::Set(GetClass(), this, TEXT("HearingDistance"), (double)15);
    ITRDefaults::Set(GetClass(), this, TEXT("AwarenessLowValueLevel"), (double)15);
    ITRDefaults::Set(GetClass(), this, TEXT("AwarenessHighValueLevel"), (double)15);
    ITRDefaults::Set(GetClass(), this, TEXT("AwarenessMaxValue"), (double)15);
    ITRDefaults::Set(GetClass(), this, TEXT("AwarenessDecreaseMultiplier"), (double)15);
}

void UPRNpcPerceptionComponent::VerifyPlayerSelection() {
}

void UPRNpcPerceptionComponent::UnselectPlayer() {
}

void UPRNpcPerceptionComponent::SpotPlayer() {
}

void UPRNpcPerceptionComponent::SpotActor(const AActor* Actor) {
}

void UPRNpcPerceptionComponent::SetupInitialState(float InitialAwareness, bool bPlayerInitiallySelected) {
}

void UPRNpcPerceptionComponent::SetSelection(const AActor* Actor, bool& bSuccess, AActor*& Selection) {
}

void UPRNpcPerceptionComponent::SetPoiFollowSelection(const bool bShouldFollow) {
}

void UPRNpcPerceptionComponent::SetPoi(const FVector& NewPoi, bool& bChanged, AActor*& POIActor) {
}

void UPRNpcPerceptionComponent::SelectPlayer() {
}

void UPRNpcPerceptionComponent::SelectionIsAlive(bool& bAlive) const {
}

void UPRNpcPerceptionComponent::IsSpotted(const AActor* Actor, bool& bSpotted) const {
}

void UPRNpcPerceptionComponent::IsPlayerSpotted(bool& bSpotted) const {
}

void UPRNpcPerceptionComponent::IsPlayerSelectionAlive(bool& bAlive) const {
}

void UPRNpcPerceptionComponent::IsEnemy(const AActor* Actor, bool& bIsEnemy) const {
}

void UPRNpcPerceptionComponent::IsActorSpottable(const AActor* Actor, bool& bSpottable) const {
}

void UPRNpcPerceptionComponent::HaveSelection(bool& bValid) {
}

void UPRNpcPerceptionComponent::GetSensedPlayerLocation(bool& bValid, FVector& Location) {
}

void UPRNpcPerceptionComponent::GetSelection(bool& bValid, AActor*& Selection, FTransform& BodyTransform) const {
}

void UPRNpcPerceptionComponent::GetPoi(bool& bValid, AActor*& POIActor) {
}

void UPRNpcPerceptionComponent::GetPlayerSelection(bool& bValid, AActor*& Player, FTransform& BodyTransform) const {
}

void UPRNpcPerceptionComponent::GetClosestActor(bool& bSuccess, AActor*& Actor) const {
}

void UPRNpcPerceptionComponent::GetAwareness(float& Value, EAwarenessLevel& Level) const {
}

void UPRNpcPerceptionComponent::ChangeAwarenessByTag(float Strength, FName Tag) {
}

void UPRNpcPerceptionComponent::ChangeAwareness(float Value) {
}

void UPRNpcPerceptionComponent::AIPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus) {
}

