#include "RadiusAudioBoxComponent.h"
#include "ITRDefaults.h"

URadiusAudioBoxComponent::URadiusAudioBoxComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bSimulatePhysics"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bOverrideMass"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bEnableGravity"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bAutoWeld"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bStartAwake"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bGenerateWakeEvents"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bUpdateMassWhenScaleChanges"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.ObjectType"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionEnabled"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.SleepFamily"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.DOFMode"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bUseCCD"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bIgnoreAnalyticCollisions"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bNotifyRigidBodyCollision"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bLockTranslation"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bLockRotation"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bLockXTranslation"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bLockYTranslation"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bLockZTranslation"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bLockXRotation"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bLockYRotation"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bLockZRotation"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bOverrideMaxAngularVelocity"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bOverrideMaxDepenetrationVelocity"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bOverrideWalkableSlopeOnInstance"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.bInterpolateWhenSubStepping"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionProfileName"), TEXT("Custom"));
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.PositionSolverIterationCount"), (double)8);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.VelocitySolverIterationCount"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.WorldStatic"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.WorldDynamic"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Pawn"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Visibility"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Camera"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.PhysicsBody"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Vehicle"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.Destructible"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel1"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel2"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel3"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel4"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel5"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.EngineTraceChannel6"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel1"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel2"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel3"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel4"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel5"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel6"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel7"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel8"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel9"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel10"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel11"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel12"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel13"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel14"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel15"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel16"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel17"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel18"), (double)2);
    ITRDefaults::SetNum(GetClass(), this, TEXT("BodyInstance.CollisionResponses.ResponseArray"), 0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.MaxDepenetrationVelocity"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.MassInKgOverride"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.LinearDamping"), (double)0.00999999978);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.AngularDamping"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CustomDOFPlaneNormal.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CustomDOFPlaneNormal.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CustomDOFPlaneNormal.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.COMNudge.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.COMNudge.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.COMNudge.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.MassScale"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.InertiaTensorScale.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.InertiaTensorScale.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.InertiaTensorScale.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.WalkableSlopeOverride.WalkableSlopeBehavior"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.WalkableSlopeOverride.WalkableSlopeAngle"), (double)0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("BodyInstance.PhysMaterialOverride"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.MaxAngularVelocity"), (double)3600);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.CustomSleepThresholdMultiplier"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.StabilizationThresholdMultiplier"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("BodyInstance.PhysicsBlendWeight"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("bEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("Settings.bApplyReverb"), true);
    ITRDefaults::SetObject(GetClass(), this, TEXT("Settings.ReverbEffect"), nullptr);
    ITRDefaults::SetObject(GetClass(), this, TEXT("Settings.ReverbPluginEffect"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("Settings.Volume"), (double)0.5);
    ITRDefaults::Set(GetClass(), this, TEXT("Settings.FadeTime"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("AmbientZoneSettings.bIsWorldSettings"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("AmbientZoneSettings.ExteriorVolume"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("AmbientZoneSettings.ExteriorTime"), (double)0.5);
    ITRDefaults::Set(GetClass(), this, TEXT("AmbientZoneSettings.ExteriorLPF"), (double)20000);
    ITRDefaults::Set(GetClass(), this, TEXT("AmbientZoneSettings.ExteriorLPFTime"), (double)0.5);
    ITRDefaults::Set(GetClass(), this, TEXT("AmbientZoneSettings.InteriorVolume"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("AmbientZoneSettings.InteriorTime"), (double)0.5);
    ITRDefaults::Set(GetClass(), this, TEXT("AmbientZoneSettings.InteriorLPF"), (double)20000);
    ITRDefaults::Set(GetClass(), this, TEXT("AmbientZoneSettings.InteriorLPFTime"), (double)0.5);
}

void URadiusAudioBoxComponent::UpdateVolumeSettings() {
}

void URadiusAudioBoxComponent::SetPriority(float NewPriority) {
}

void URadiusAudioBoxComponent::SetEnabled(bool bNewEnabled) {
}

void URadiusAudioBoxComponent::OnOwnerDestroyed(AActor* DestoryedObject) {
}

