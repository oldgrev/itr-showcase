#include "PRCharacter.h"
#include "AIEdPerceptionComp.h"
#include "AliveStatsComponent.h"
#include "Components/AudioComponent.h"
#include "Components/WidgetComponent.h"
#include "ITRDefaults.h"
#include "PRNpcPerceptionComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"

APRCharacter::APRCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UAliveStatsComponent* Sub0 = Cast<UAliveStatsComponent>(GetDefaultSubobjectByName(TEXT("Alive Stats Component")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UAliveStatsComponent>(TEXT("Alive Stats Component"));
    UAIPerceptionStimuliSourceComponent* Sub1 = Cast<UAIPerceptionStimuliSourceComponent>(GetDefaultSubobjectByName(TEXT("Perception Stimuli Source Component")));
    if (!Sub1) Sub1 = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Perception Stimuli Source Component"));
    UAIEdPerceptionComp* Sub2 = Cast<UAIEdPerceptionComp>(GetDefaultSubobjectByName(TEXT("AI Ed Perception Component")));
    if (!Sub2) Sub2 = CreateDefaultSubobject<UAIEdPerceptionComp>(TEXT("AI Ed Perception Component"));
    UPRNpcPerceptionComponent* Sub3 = Cast<UPRNpcPerceptionComponent>(GetDefaultSubobjectByName(TEXT("Npc Perception Component")));
    if (!Sub3) Sub3 = CreateDefaultSubobject<UPRNpcPerceptionComponent>(TEXT("Npc Perception Component"));
    UAudioComponent* Sub4 = Cast<UAudioComponent>(GetDefaultSubobjectByName(TEXT("Audio Idle Component")));
    if (!Sub4) Sub4 = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Idle Component"));
    UWidgetComponent* Sub5 = Cast<UWidgetComponent>(GetDefaultSubobjectByName(TEXT("DebugWidget")));
    if (!Sub5) Sub5 = CreateDefaultSubobject<UWidgetComponent>(TEXT("DebugWidget"));
    Sub3->SetupAttachment(Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("CollisionCylinder"))));
    Sub4->SetupAttachment(Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("CollisionCylinder"))));
    Sub5->SetupAttachment(Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("CollisionCylinder"))));
    if (UObject* S = GetDefaultSubobjectByName(TEXT("CollisionCylinder"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bSimulatePhysics"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideMass"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bEnableGravity"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bAutoWeld"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bStartAwake"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bGenerateWakeEvents"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bUpdateMassWhenScaleChanges"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.ObjectType"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionEnabled"), (double)3);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.SleepFamily"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.DOFMode"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bUseCCD"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bIgnoreAnalyticCollisions"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bNotifyRigidBodyCollision"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockTranslation"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockRotation"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockXTranslation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockYTranslation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockZTranslation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockXRotation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockYRotation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockZRotation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideMaxAngularVelocity"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideMaxDepenetrationVelocity"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideWalkableSlopeOnInstance"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bInterpolateWhenSubStepping"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionProfileName"), TEXT("Custom"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.PositionSolverIterationCount"), (double)8);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.VelocitySolverIterationCount"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.WorldStatic"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.WorldDynamic"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Pawn"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Visibility"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Camera"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.PhysicsBody"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Vehicle"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Destructible"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel1"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel2"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel3"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel4"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel5"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel6"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel1"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel2"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel3"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel4"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel5"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel6"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel7"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel8"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel9"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel10"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel11"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel12"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel13"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel14"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel15"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel16"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel17"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel18"), (double)2);
        ITRDefaults::SetNum(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray"), 9);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[0].Channel"), TEXT("Visibility"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[0].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[1].Channel"), TEXT("Camera"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[1].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[2].Channel"), TEXT("PhysicsBody"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[2].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[3].Channel"), TEXT("Vehicle"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[3].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[4].Channel"), TEXT("Destructible"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[4].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[5].Channel"), TEXT("Projectile"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[5].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[6].Channel"), TEXT("hand"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[6].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[7].Channel"), TEXT("Trigger"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[7].Response"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[8].Channel"), TEXT("PawnLeaning"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[8].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.MaxDepenetrationVelocity"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.MassInKgOverride"), (double)100);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.LinearDamping"), (double)0.00999999978);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.AngularDamping"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CustomDOFPlaneNormal.X"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CustomDOFPlaneNormal.Y"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CustomDOFPlaneNormal.Z"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.COMNudge.X"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.COMNudge.Y"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.COMNudge.Z"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.MassScale"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.InertiaTensorScale.X"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.InertiaTensorScale.Y"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.InertiaTensorScale.Z"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.WalkableSlopeOverride.WalkableSlopeBehavior"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.WalkableSlopeOverride.WalkableSlopeAngle"), (double)0);
        ITRDefaults::SetObject(S->GetClass(), S, TEXT("BodyInstance.PhysMaterialOverride"), nullptr);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.MaxAngularVelocity"), (double)3600);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CustomSleepThresholdMultiplier"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.StabilizationThresholdMultiplier"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.PhysicsBlendWeight"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("CanCharacterStepUpOn"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("CapsuleHalfHeight"), (double)88);
        ITRDefaults::Set(S->GetClass(), S, TEXT("CapsuleRadius"), (double)34);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bCanEverAffectNavigation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bDynamicObstacle"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bGenerateOverlapEvents"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldUpdatePhysicsVolume"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("CharMoveComp"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("DefaultLandMovementMode"), (double)2);
        ITRDefaults::SetObject(S->GetClass(), S, TEXT("UpdatedComponent"), GetDefaultSubobjectByName(TEXT("CollisionCylinder")));
        ITRDefaults::Set(S->GetClass(), S, TEXT("bDontTeleportWhenLeavingNavWalking"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bSweepWhileNavWalking"), false);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("CharacterMesh0"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bSimulatePhysics"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideMass"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bEnableGravity"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bAutoWeld"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bStartAwake"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bGenerateWakeEvents"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bUpdateMassWhenScaleChanges"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.ObjectType"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionEnabled"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.SleepFamily"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.DOFMode"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bUseCCD"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bIgnoreAnalyticCollisions"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bNotifyRigidBodyCollision"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockTranslation"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockRotation"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockXTranslation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockYTranslation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockZTranslation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockXRotation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockYRotation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bLockZRotation"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideMaxAngularVelocity"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideMaxDepenetrationVelocity"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideWalkableSlopeOnInstance"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bInterpolateWhenSubStepping"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionProfileName"), TEXT("Custom"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.PositionSolverIterationCount"), (double)8);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.VelocitySolverIterationCount"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.WorldStatic"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.WorldDynamic"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Pawn"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Visibility"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Camera"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.PhysicsBody"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Vehicle"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Destructible"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel1"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel2"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel3"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel4"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel5"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel6"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel1"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel2"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel3"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel4"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel5"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel6"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel7"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel8"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel9"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel10"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel11"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel12"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel13"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel14"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel15"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel16"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel17"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel18"), (double)1);
        ITRDefaults::SetNum(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray"), 5);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[0].Channel"), TEXT("Pawn"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[0].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[1].Channel"), TEXT("Visibility"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[1].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[2].Channel"), TEXT("Vehicle"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[2].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[3].Channel"), TEXT("hand"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[3].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[4].Channel"), TEXT("PlayerMesh"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[4].Response"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.MaxDepenetrationVelocity"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.MassInKgOverride"), (double)100);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.LinearDamping"), (double)0.00999999978);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.AngularDamping"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CustomDOFPlaneNormal.X"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CustomDOFPlaneNormal.Y"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CustomDOFPlaneNormal.Z"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.COMNudge.X"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.COMNudge.Y"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.COMNudge.Z"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.MassScale"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.InertiaTensorScale.X"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.InertiaTensorScale.Y"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.InertiaTensorScale.Z"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.WalkableSlopeOverride.WalkableSlopeBehavior"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.WalkableSlopeOverride.WalkableSlopeAngle"), (double)0);
        ITRDefaults::SetObject(S->GetClass(), S, TEXT("BodyInstance.PhysMaterialOverride"), nullptr);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.MaxAngularVelocity"), (double)3600);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CustomSleepThresholdMultiplier"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.StabilizationThresholdMultiplier"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.PhysicsBlendWeight"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("VisibilityBasedAnimTickOption"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bGenerateOverlapEvents"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bUpdateOverlapsOnAnimationFinalize"), false);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Npc Perception Component"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("RelativeLocation.X"), (double)25);
        ITRDefaults::Set(S->GetClass(), S, TEXT("RelativeLocation.Y"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("RelativeLocation.Z"), (double)85);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Audio Idle Component"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("DebugWidget"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("RelativeLocation.X"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("RelativeLocation.Y"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("RelativeLocation.Z"), (double)93);
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickInterval"), (double)0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("CollisionCylinder")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("Mesh"), GetDefaultSubobjectByName(TEXT("CharacterMesh0")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("CharacterMovement"), GetDefaultSubobjectByName(TEXT("CharMoveComp")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("CapsuleComponent"), GetDefaultSubobjectByName(TEXT("CollisionCylinder")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("DebugWidget"), GetDefaultSubobjectByName(TEXT("DebugWidget")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("PerceptionComponent"), GetDefaultSubobjectByName(TEXT("Npc Perception Component")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("AudioIdle"), GetDefaultSubobjectByName(TEXT("Audio Idle Component")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("AIPerceptionStimuliSource"), GetDefaultSubobjectByName(TEXT("Perception Stimuli Source Component")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("AIEdPerceptionComponent"), GetDefaultSubobjectByName(TEXT("AI Ed Perception Component")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("AliveStatsComponent"), GetDefaultSubobjectByName(TEXT("Alive Stats Component")));
    ITRDefaults::Set(GetClass(), this, TEXT("WalkSpeed"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("IdleTime"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("LootPossibility"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("IdleWalkRadius"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("CharName"), TEXT("Monster"));
    ITRDefaults::Set(GetClass(), this, TEXT("LootPossibilityOverride"), (double)-1);
    ITRDefaults::Set(GetClass(), this, TEXT("POI.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("POI.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("POI.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ValidDistanceToPlayer"), (double)250);
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
}

void APRCharacter::WalkToLocation(const FVector Location) {
}

void APRCharacter::WalkToActorLocation(AActor* Actor) {
}

void APRCharacter::SwitchAiDebug() {
}

void APRCharacter::SpawnLoot() const {
}

void APRCharacter::SetupState(const FNPCGameData& NPC_data, TArray<FName> BoolNames, TArray<bool> BoolValues) {
}

void APRCharacter::SetEnableEverything(const bool enable) {
}

void APRCharacter::SetEnableAdditionalThings_Implementation(bool enable) {
}

void APRCharacter::SetCommand(ECharCommand NewCommand, bool Force) {
}

void APRCharacter::SetBrainEnabled(const bool enable) const {
}

bool APRCharacter::SelectAndAttackClosest() {
    return {};
}

bool APRCharacter::SelectAndAttack(AActor* Actor) {
    return {};
}

void APRCharacter::SaveGameData() {
}

void APRCharacter::RestartTree() const {
}

void APRCharacter::ReappearOutOfSight() {
}

void APRCharacter::ReappearCoverCallback(const FNpcPointQueryResult& QueryResult) {
}

void APRCharacter::ProcessNoise(const FName Tag, const FVector Location) {
}

void APRCharacter::ProcessDamage(AActor* causer, float Damage) {
}

void APRCharacter::PrintMessage(const FString& MessageToPrint) const {
}

void APRCharacter::OnHeardNoise(AActor* Actor, FVector Location, float Strength, FName Tag) {
}

void APRCharacter::OnDeath_Implementation(bool bEnableRagdoll) {
}

void APRCharacter::OnDamaged_Implementation(AActor* causer, const float Damage) {
}

void APRCharacter::NpcAwarenessLevelChanged(const EAwarenessLevel PrevLevel, const EAwarenessLevel NewLevel) {
}

void APRCharacter::LoadBaseSettings() {
}

void APRCharacter::LoadAdditionalSettings_Implementation() {
}

bool APRCharacter::IsPlayerNear() const {
    return {};
}

bool APRCharacter::IsLocInValidRange(FVector Location) const {
    return {};
}

bool APRCharacter::IsEnabled() const {
    return {};
}

void APRCharacter::InvestigateLocation(FVector Location) {
}

void APRCharacter::HealthEnd() {
}

FVector APRCharacter::GetIdleOriginPoint() const {
    return {};
}

float APRCharacter::GetFootstepNoiseRange() const {
    return {};
}

EAwarenessLevel APRCharacter::GetAwarenessLevel() const {
    return {};
}

float APRCharacter::GetAttackMoveDilationAngle() const {
    return {};
}

float APRCharacter::GetAttackLostLocationTime() const {
    return {};
}

void APRCharacter::EnableRagdoll() {
}

void APRCharacter::DestroyController() {
}

void APRCharacter::CharEnabled_Implementation() {
}

void APRCharacter::AlertNearbyMonsters(AActor* causer, const bool bDeath) {
}

