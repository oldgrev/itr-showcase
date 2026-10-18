#include "CharBroadcast.h"
#include "Components/SphereComponent.h"
#include "ITRDefaults.h"

ACharBroadcast::ACharBroadcast(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    USphereComponent* Sub0 = Cast<USphereComponent>(GetDefaultSubobjectByName(TEXT("Broadcast Sphere")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<USphereComponent>(TEXT("Broadcast Sphere"));
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Broadcast Sphere"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bSimulatePhysics"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideMass"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bEnableGravity"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bAutoWeld"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bStartAwake"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bGenerateWakeEvents"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bUpdateMassWhenScaleChanges"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.ObjectType"), (double)17);
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
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.WorldStatic"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.WorldDynamic"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Pawn"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Visibility"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Camera"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.PhysicsBody"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Vehicle"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Destructible"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel1"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel2"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel3"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel4"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel5"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel6"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel1"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel2"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel3"), (double)1);
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
        ITRDefaults::SetNum(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray"), 9);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[0].Channel"), TEXT("WorldStatic"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[0].Response"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[1].Channel"), TEXT("WorldDynamic"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[1].Response"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[2].Channel"), TEXT("Pawn"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[2].Response"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[3].Channel"), TEXT("Visibility"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[3].Response"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[4].Channel"), TEXT("Camera"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[4].Response"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[5].Channel"), TEXT("PhysicsBody"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[5].Response"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[6].Channel"), TEXT("Vehicle"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[6].Response"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[7].Channel"), TEXT("Destructible"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[7].Response"), (double)1);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[8].Channel"), TEXT("PlayerMesh"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[8].Response"), (double)1);
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
        ITRDefaults::SetObject(S->GetClass(), S, TEXT("ShapeBodySetup"), GetDefaultSubobjectByName(TEXT("BodySetup_2147482633")));
        ITRDefaults::Set(S->GetClass(), S, TEXT("SphereRadius"), (double)1500);
    }
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("Broadcast Sphere")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("Sphere"), GetDefaultSubobjectByName(TEXT("Broadcast Sphere")));
    ITRDefaults::Set(GetClass(), this, TEXT("Radius"), (double)1500);
    ITRDefaults::Set(GetClass(), this, TEXT("LifeTime"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("MissionKillPoint.TagName"), TEXT("None"));
}

ACharBroadcast* ACharBroadcast::SpawnBroadcast(UObject* WorldContext, FTransform SpawnTransform, FGameplayTag MissionKillPointTag, float LifeSpan, float SphereRadius) {
    return {};
}

void ACharBroadcast::AlertOthers(AActor* Caller, AActor*& Target, FTransform Location) {
}

