#include "PRPlayerCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "ITRDefaults.h"
#include "PRPlayerGripSystemComponent.h"
#include "RadiusAutomationComponent.h"
#include "RadiusPlayerMovementComponent.h"

APRPlayerCharacter::APRPlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    USkeletalMeshComponent* Sub0 = Cast<USkeletalMeshComponent>(GetDefaultSubobjectByName(TEXT("SKBody")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SKBody"));
    UPRPlayerGripSystemComponent* Sub1 = Cast<UPRPlayerGripSystemComponent>(GetDefaultSubobjectByName(TEXT("PlayerGripSystem")));
    if (!Sub1) Sub1 = CreateDefaultSubobject<UPRPlayerGripSystemComponent>(TEXT("PlayerGripSystem"));
    URadiusAutomationComponent* Sub2 = Cast<URadiusAutomationComponent>(GetDefaultSubobjectByName(TEXT("Automation")));
    if (!Sub2) Sub2 = CreateDefaultSubobject<URadiusAutomationComponent>(TEXT("Automation"));
    URadiusPlayerMovementComponent* Sub3 = Cast<URadiusPlayerMovementComponent>(GetDefaultSubobjectByName(TEXT("Movement")));
    if (!Sub3) Sub3 = CreateDefaultSubobject<URadiusPlayerMovementComponent>(TEXT("Movement"));
    Sub0->SetupAttachment(Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("CollisionCylinder"))));
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
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.WorldDynamic"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Pawn"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Visibility"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Camera"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.PhysicsBody"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Vehicle"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Destructible"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel1"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel2"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel3"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel4"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel5"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel6"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel1"), (double)0);
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
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel17"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel18"), (double)0);
        ITRDefaults::SetNum(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray"), 16);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[0].Channel"), TEXT("WorldDynamic"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[0].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[1].Channel"), TEXT("Pawn"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[1].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[2].Channel"), TEXT("Visibility"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[2].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[3].Channel"), TEXT("Camera"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[3].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[4].Channel"), TEXT("PhysicsBody"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[4].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[5].Channel"), TEXT("Vehicle"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[5].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[6].Channel"), TEXT("Destructible"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[6].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[7].Channel"), TEXT("EngineTraceChannel2"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[7].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[8].Channel"), TEXT("EngineTraceChannel3"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[8].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[9].Channel"), TEXT("EngineTraceChannel4"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[9].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[10].Channel"), TEXT("EngineTraceChannel5"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[10].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[11].Channel"), TEXT("EngineTraceChannel6"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[11].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[12].Channel"), TEXT("Projectile"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[12].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[13].Channel"), TEXT("hand"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[13].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[14].Channel"), TEXT("PawnLeaning"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[14].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[15].Channel"), TEXT("PlayerMesh"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[15].Response"), (double)0);
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
        ITRDefaults::SetObject(S->GetClass(), S, TEXT("ShapeBodySetup"), GetDefaultSubobjectByName(TEXT("BodySetup_2147482631")));
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldUpdatePhysicsVolume"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("CharMoveComp"))) {
        ITRDefaults::SetObject(S->GetClass(), S, TEXT("UpdatedComponent"), GetDefaultSubobjectByName(TEXT("CollisionCylinder")));
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("CharacterMesh0"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bSimulatePhysics"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideMass"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bEnableGravity"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bAutoWeld"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bStartAwake"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bGenerateWakeEvents"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bUpdateMassWhenScaleChanges"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.ObjectType"), (double)31);
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
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionProfileName"), TEXT("CharacterMesh"));
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
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("NetSmoother"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("VR Replicated Camera"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Parent Relative Attachment"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Left Grip Motion Controller"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Right Grip Motion Controller"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("MotionSource"), TEXT("Right"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("SKBody"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("bShouldBeAttached"), true);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("PlayerGripSystem"))) {
        ITRDefaults::SetObject(S->GetClass(), S, TEXT("DistanceGripManager"), GetDefaultSubobjectByName(TEXT("Distance Grip Manager")));
    }
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("CollisionCylinder")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("Mesh"), GetDefaultSubobjectByName(TEXT("CharacterMesh0")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("CharacterMovement"), GetDefaultSubobjectByName(TEXT("CharMoveComp")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("CapsuleComponent"), GetDefaultSubobjectByName(TEXT("CollisionCylinder")));
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.LinearVelocity.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.LinearVelocity.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.LinearVelocity.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.AngularVelocity.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.AngularVelocity.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.AngularVelocity.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.Location.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.Location.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.Location.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.Rotation.Pitch"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.Rotation.Yaw"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.Rotation.Roll"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.bSimulatedPhysicSleep"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.bRepPhysics"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.LocationQuantizationLevel"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.VelocityQuantizationLevel"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.RotationQuantizationLevel"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.bJustTeleported"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.bJustTeleportedGrips"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("ReplicatedMovementVR.Owner"), TEXT("/Script/IntoTheRadius.Default__PRPlayerCharacter"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("NetSmoother"), GetDefaultSubobjectByName(TEXT("NetSmoother")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("VRMovementReference"), GetDefaultSubobjectByName(TEXT("CharMoveComp")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("VRReplicatedCamera"), GetDefaultSubobjectByName(TEXT("VR Replicated Camera")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("ParentRelativeAttachment"), GetDefaultSubobjectByName(TEXT("Parent Relative Attachment")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("LeftMotionController"), GetDefaultSubobjectByName(TEXT("Left Grip Motion Controller")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("RightMotionController"), GetDefaultSubobjectByName(TEXT("Right Grip Motion Controller")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("VRRootReference"), GetDefaultSubobjectByName(TEXT("CollisionCylinder")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("SKBody"), GetDefaultSubobjectByName(TEXT("SKBody")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("GripSystemComp"), GetDefaultSubobjectByName(TEXT("PlayerGripSystem")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("AutomationComp"), GetDefaultSubobjectByName(TEXT("Automation")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("RadiusPlayerMovementComponent"), GetDefaultSubobjectByName(TEXT("Movement")));
    ITRDefaults::Set(GetClass(), this, TEXT("MovementVector.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("MovementVector.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("MovementVector.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.ObjectTransform.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.ObjectTransform.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.ObjectTransform.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.ObjectTransform.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.ObjectTransform.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.ObjectTransform.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.ObjectTransform.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.ObjectTransform.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.ObjectTransform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.ObjectTransform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.GripPoint.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.GripPoint.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.GripPoint.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.GripPoint.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.GripPoint.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.GripPoint.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.GripPoint.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.GripPoint.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.GripPoint.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.GripPoint.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.TriggerPoint.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.TriggerPoint.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.TriggerPoint.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.TriggerPoint.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.TriggerPoint.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.TriggerPoint.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.TriggerPoint.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.TriggerPoint.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.TriggerPoint.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.TriggerPoint.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.HandTransformWhenOverlap.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.HandTransformWhenOverlap.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.HandTransformWhenOverlap.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.HandTransformWhenOverlap.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.HandTransformWhenOverlap.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.HandTransformWhenOverlap.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.HandTransformWhenOverlap.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.HandTransformWhenOverlap.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.HandTransformWhenOverlap.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripRight.HandTransformWhenOverlap.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.ObjectTransform.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.ObjectTransform.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.ObjectTransform.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.ObjectTransform.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.ObjectTransform.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.ObjectTransform.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.ObjectTransform.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.ObjectTransform.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.ObjectTransform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.ObjectTransform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.GripPoint.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.GripPoint.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.GripPoint.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.GripPoint.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.GripPoint.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.GripPoint.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.GripPoint.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.GripPoint.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.GripPoint.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.GripPoint.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.TriggerPoint.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.TriggerPoint.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.TriggerPoint.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.TriggerPoint.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.TriggerPoint.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.TriggerPoint.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.TriggerPoint.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.TriggerPoint.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.TriggerPoint.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.TriggerPoint.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.HandTransformWhenOverlap.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.HandTransformWhenOverlap.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.HandTransformWhenOverlap.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.HandTransformWhenOverlap.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.HandTransformWhenOverlap.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.HandTransformWhenOverlap.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.HandTransformWhenOverlap.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.HandTransformWhenOverlap.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.HandTransformWhenOverlap.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("OverlapGripLeft.HandTransformWhenOverlap.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.ObjectTransform.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.ObjectTransform.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.ObjectTransform.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.ObjectTransform.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.ObjectTransform.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.ObjectTransform.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.ObjectTransform.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.ObjectTransform.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.ObjectTransform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.ObjectTransform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.GripPoint.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.GripPoint.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.GripPoint.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.GripPoint.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.GripPoint.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.GripPoint.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.GripPoint.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.GripPoint.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.GripPoint.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.GripPoint.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.TriggerPoint.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.TriggerPoint.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.TriggerPoint.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.TriggerPoint.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.TriggerPoint.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.TriggerPoint.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.TriggerPoint.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.TriggerPoint.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.TriggerPoint.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.TriggerPoint.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.HandTransformWhenOverlap.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.HandTransformWhenOverlap.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.HandTransformWhenOverlap.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.HandTransformWhenOverlap.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.HandTransformWhenOverlap.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.HandTransformWhenOverlap.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.HandTransformWhenOverlap.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.HandTransformWhenOverlap.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.HandTransformWhenOverlap.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetRight.HandTransformWhenOverlap.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.ObjectTransform.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.ObjectTransform.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.ObjectTransform.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.ObjectTransform.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.ObjectTransform.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.ObjectTransform.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.ObjectTransform.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.ObjectTransform.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.ObjectTransform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.ObjectTransform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.GripPoint.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.GripPoint.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.GripPoint.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.GripPoint.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.GripPoint.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.GripPoint.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.GripPoint.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.GripPoint.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.GripPoint.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.GripPoint.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.TriggerPoint.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.TriggerPoint.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.TriggerPoint.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.TriggerPoint.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.TriggerPoint.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.TriggerPoint.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.TriggerPoint.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.TriggerPoint.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.TriggerPoint.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.TriggerPoint.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.HandTransformWhenOverlap.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.HandTransformWhenOverlap.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.HandTransformWhenOverlap.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.HandTransformWhenOverlap.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.HandTransformWhenOverlap.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.HandTransformWhenOverlap.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.HandTransformWhenOverlap.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.HandTransformWhenOverlap.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.HandTransformWhenOverlap.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("SelectedGripTargetLeft.HandTransformWhenOverlap.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ClimbGripLocation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ClimbGripLocation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ClimbGripLocation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceGripPoint_R.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceGripPoint_R.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceGripPoint_R.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceGripPoint_L.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceGripPoint_L.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("DistanceGripPoint_L.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PlayerMeshEyeHeight"), (double)171);
    ITRDefaults::Set(GetClass(), this, TEXT("NeckOffset"), (double)17);
    ITRDefaults::Set(GetClass(), this, TEXT("PlayerMeshHeight"), (double)183.5);
    ITRDefaults::Set(GetClass(), this, TEXT("MinPlayerHeight"), (double)120);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxPlayerHeight"), (double)220);
}

void APRPlayerCharacter::UpdateIndicatorsVisibility_Native() {
}

bool APRPlayerCharacter::TryToGrabObject_Native(UObject* ObjectToTryToGrab, const FTransform& WorldTransform, UGripMotionControllerComponent* CallingHand, UGripMotionControllerComponent* OtherHand, bool bIsSlotGrip, EControllerHand EnumHand, bool bIsDistanceGrip) {
    return {};
}

void APRPlayerCharacter::TryDropSimulating_Native(UGripMotionControllerComponent* hand) {
}

void APRPlayerCharacter::TakeInHand_Native(UGripMotionControllerComponent* hand, UObject* Object, bool bIsCallerHandLeft) {
}

void APRPlayerCharacter::RecreateBackpack_Native() {
}

void APRPlayerCharacter::ProcessDamageArmor(const float Damage, const EDamageCategory DamageCategory, AActor* causer, float& ResultDamage) {
}

void APRPlayerCharacter::PositionClimbingIndicatorNative(bool bIsLeftHand, bool bReset) {
}

void APRPlayerCharacter::OverlapsUINative(const UPrimitiveComponent* Prim, bool bLeft, bool& bOverlaps) const {
}

void APRPlayerCharacter::OverlapGripNative(bool bLeft) {
}

void APRPlayerCharacter::IsCrouch(bool& bCrouch) {
}

bool APRPlayerCharacter::IsAliveNative() {
    return {};
}

void APRPlayerCharacter::InitClimbing_Native(UGripMotionControllerComponent* hand, UObject* Object, bool isObjectRelative) {
}

bool APRPlayerCharacter::GripOrDropObject_Native(UGripMotionControllerComponent* CallingHand, UGripMotionControllerComponent* OtherHand) {
    return {};
}

void APRPlayerCharacter::GripOrDrop_Native(UGripMotionControllerComponent* CallingHand, UGripMotionControllerComponent* OtherHand, const bool bIsGrip, const USphereComponent* GrabSphere) {
}

void APRPlayerCharacter::GetNearestOverlapObjectNative(USphereComponent* OverlapComponent, UGripMotionControllerComponent* hand, UGripMotionControllerComponent* OtherHand, UObject*& OutNearestObject, bool& bOutImplementsInterface, FTransform& OutObjectTransform, bool& bOutCanBeClimbed, UPrimitiveComponent*& OutPrimitive, bool& bOutIsDistanceGrip, FTransform& OutGripPoint, bool& bOutIsSlotGrip, UPrimitiveComponent*& OutTriggerPrimitive, FTransform& OutTriggerTransform, bool& bOutSecondary, FTransform& OutHandTransformWhenOverlap, EPRHandPoseGeometryType& OutGeometryType, EPRHandPoseNumber& OutPoseNumber) {
}

void APRPlayerCharacter::GetHandDataNative(bool bLeftHand, FTransform& ControllerTransform, FTransform& HandWorldTransform, FTransform& HandShiftTransform, UObject*& Object, bool& SecondaryGrip, EPRHandPoseGeometryType& HandPoseGeometryType, EPRHandPoseNumber& HandPoseNumber) {
}

bool APRPlayerCharacter::DropOrRetakeOrHolster_Native(UGripMotionControllerComponent* CallingHand, UObject* ObjectToGrip, const bool bSecondaryGrip, const bool bZeroVelocity) {
    return {};
}

bool APRPlayerCharacter::DropOrHolster_Native(UGripMotionControllerComponent* CallingHand, UObject* ObjectToGrip, const bool bSecondaryGrip) {
    return {};
}

bool APRPlayerCharacter::DoesPlayerHolsterPreventInteraction(const AActor* Interactable) {
    return {};
}

void APRPlayerCharacter::ClearClimbing_Native(const bool bBecauseOfStepUp) {
}

bool APRPlayerCharacter::CheckTriggerOverlaps_Native(const USphereComponent* GrabSphere, UGripMotionControllerComponent* CallingHand) {
    return {};
}

void APRPlayerCharacter::CheckHolster_Native(UObject* Object, const bool bRemove, const bool bIsLeftHand, bool& bHolsterFound, bool& bHolsterOk, UHolsterComponent*& Holster) {
}

void APRPlayerCharacter::BeamPointerToggleNative(bool bOnOff, FVector TargetPoint, bool bIsLeftHand, bool bUIGrip) {
}

