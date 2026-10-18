#include "PRALSCharacter.h"
#include "ITRDefaults.h"

APRALSCharacter::APRALSCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
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
    ITRDefaults::Set(GetClass(), this, TEXT("Acceleration.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("Acceleration.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("Acceleration.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("LastVelocityRotation.Pitch"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("LastVelocityRotation.Yaw"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("LastVelocityRotation.Roll"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("LastMovementInputRotation.Pitch"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("LastMovementInputRotation.Yaw"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("LastMovementInputRotation.Roll"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PreviousVelocity.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PreviousVelocity.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PreviousVelocity.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DesiredRotationMode"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("DesiredGait"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("LookUpDownRate"), (double)1.25);
    ITRDefaults::Set(GetClass(), this, TEXT("LookLeftRightRate"), (double)1.25);
    ITRDefaults::SetObject(GetClass(), this, TEXT("MovementModel.DataTable"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("MovementModel.RowName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("TargetRotation.Pitch"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("TargetRotation.Yaw"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("TargetRotation.Roll"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("LastRagdollVelocity.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("LastRagdollVelocity.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("LastRagdollVelocity.Z"), (double)0);
}

void APRALSCharacter::UpdateGroundedRotation() {
}

void APRALSCharacter::UpdateDynamicMovementSettings(EGait AllowedGait) {
}

void APRALSCharacter::UpdateCharacterMovement() {
}

void APRALSCharacter::SmoothCharacterRotation(FRotator Target, float TargetInterpSpeed, float ActorInterpSpeed) {
}

void APRALSCharacter::SetMovementModel() {
}

void APRALSCharacter::SetEssentialValues() {
}

void APRALSCharacter::SetActorLocationDuringRagdoll() {
}

bool APRALSCharacter::SetActorLocationAndRotation(FVector NewLocation, FRotator NewRotation, bool bSweep, bool bTeleport, FHitResult& OutSweepHitResult) {
    return {};
}

void APRALSCharacter::RagdollUpdate() {
}

void APRALSCharacter::RagdollStart() {
}

void APRALSCharacter::RagdollEnd() {
}

void APRALSCharacter::OnViewModeChanged(EViewMode NewViewMode) {
}

void APRALSCharacter::OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) {
}

void APRALSCharacter::OnStanceChanged(EStance NewStance) {
}

void APRALSCharacter::OnRotationModeChanged(ERotationMode NewRotationMode) {
}

void APRALSCharacter::OnOverlayStateChanged(EOverlayState NewOverLayState) {
}

void APRALSCharacter::OnMovementStateChanged(EMovementState NewMovementState) {
}

void APRALSCharacter::OnGaitChanged(EGait NewActualGait) {
}

void APRALSCharacter::OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) {
}

void APRALSCharacter::OnCharacterMovementModeChanged(TEnumAsByte<EMovementMode> NewMovementMode, uint8 NewCustomMode) {
}

void APRALSCharacter::OnCharacterMovementActionChanged(EMovementAction NewMovementAction) {
}

void APRALSCharacter::OnBeginPlay() {
}

void APRALSCharacter::LimitRotation(float AimYawMin, float AimYawMax, float InterpSpeed) {
}

FMovementSettings APRALSCharacter::GetTargetMovementSettings() const {
    return {};
}

UAnimMontage* APRALSCharacter::GetRollAnimation() const {
    return {};
}

float APRALSCharacter::GetMappedSpeed() const {
    return {};
}

UAnimMontage* APRALSCharacter::GetGetUpAnimation(bool bRagDollFaceUp) {
    return {};
}

FVector APRALSCharacter::GetCapsuleLocationFromBase(FVector BaseLocation, float ZOffset) const {
    return {};
}

FVector APRALSCharacter::GetCapsuleBaseLocation(float ZOffset) const {
    return {};
}

float APRALSCharacter::GetAnimCurveValue(FName CurveName) const {
    return {};
}

FRotator APRALSCharacter::GetAimingRotation() const {
    return {};
}

EGait APRALSCharacter::GetActualGait(EGait AllowedGait) const {
    return {};
}

bool APRALSCharacter::CanUpdateMovingRotation() const {
    return {};
}

bool APRALSCharacter::CanSprint() const {
    return {};
}

float APRALSCharacter::CalculateGroundedRotationRate() const {
    return {};
}

FVector APRALSCharacter::CalculateAcceleration() const {
    return {};
}

void APRALSCharacter::CacheValues() {
}

void APRALSCharacter::BeginPlay() {
}

void APRALSCharacter::AddToCharacterRotation(FRotator DeltaRotation) {
}

