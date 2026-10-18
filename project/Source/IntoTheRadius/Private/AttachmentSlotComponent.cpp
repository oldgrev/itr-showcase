#include "AttachmentSlotComponent.h"
#include "Components/BoxComponent.h"
#include "ITRDefaults.h"

UAttachmentSlotComponent::UAttachmentSlotComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UBoxComponent* Sub0 = Cast<UBoxComponent>(GetDefaultSubobjectByName(TEXT("Bounds")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UBoxComponent>(TEXT("Bounds"));
    if (UObject* S = GetDefaultSubobjectByName(TEXT("Bounds"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bSimulatePhysics"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bOverrideMass"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bEnableGravity"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bAutoWeld"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bStartAwake"), true);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bGenerateWakeEvents"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.bUpdateMassWhenScaleChanges"), false);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.ObjectType"), (double)1);
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
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.WorldStatic"), (double)0);
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
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseToChannels.GameTraceChannel18"), (double)0);
        ITRDefaults::SetNum(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray"), 18);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[0].Channel"), TEXT("WorldStatic"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[0].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[1].Channel"), TEXT("WorldDynamic"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[1].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[2].Channel"), TEXT("Pawn"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[2].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[3].Channel"), TEXT("Visibility"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[3].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[4].Channel"), TEXT("Camera"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[4].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[5].Channel"), TEXT("PhysicsBody"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[5].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[6].Channel"), TEXT("Vehicle"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[6].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[7].Channel"), TEXT("Destructible"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[7].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[8].Channel"), TEXT("EngineTraceChannel2"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[8].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[9].Channel"), TEXT("EngineTraceChannel3"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[9].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[10].Channel"), TEXT("EngineTraceChannel4"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[10].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[11].Channel"), TEXT("EngineTraceChannel5"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[11].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[12].Channel"), TEXT("EngineTraceChannel6"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[12].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[13].Channel"), TEXT("Projectile"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[13].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[14].Channel"), TEXT("hand"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[14].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[15].Channel"), TEXT("PawnLeaning"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[15].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[16].Channel"), TEXT("PlayerMesh"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[16].Response"), (double)0);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[17].Channel"), TEXT("Trigger"));
        ITRDefaults::Set(S->GetClass(), S, TEXT("BodyInstance.CollisionResponses.ResponseArray[17].Response"), (double)1);
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
        ITRDefaults::Set(S->GetClass(), S, TEXT("BoxExtent.X"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BoxExtent.Y"), (double)5);
        ITRDefaults::Set(S->GetClass(), S, TEXT("BoxExtent.Z"), (double)2);
        ITRDefaults::Set(S->GetClass(), S, TEXT("CanCharacterStepUpOn"), (double)0);
        ITRDefaults::SetObject(S->GetClass(), S, TEXT("ShapeBodySetup"), GetDefaultSubobjectByName(TEXT("BodySetup_2147482636")));
        ITRDefaults::Set(S->GetClass(), S, TEXT("ShapeColor.B"), (double)18);
        ITRDefaults::Set(S->GetClass(), S, TEXT("ShapeColor.G"), (double)156);
        ITRDefaults::Set(S->GetClass(), S, TEXT("ShapeColor.R"), (double)243);
        ITRDefaults::Set(S->GetClass(), S, TEXT("ShapeColor.A"), (double)255);
    }
    ITRDefaults::Set(GetClass(), this, TEXT("bGenerateOverlapEvents"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("CanCharacterStepUpOn"), (double)0);
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
    ITRDefaults::Set(GetClass(), this, TEXT("AttachmentType.TagName"), TEXT("None"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("BoxCollision"), GetDefaultSubobjectByName(TEXT("Bounds")));
}

void UAttachmentSlotComponent::TryDetachItem_Implementation(AActor* Attachment, bool& bSuccess) {
}

void UAttachmentSlotComponent::TryAttachItem_Implementation(AActor* Attachment, bool& bSuccess) {
}

void UAttachmentSlotComponent::SetSlotEnabled(const bool bEnable) {
}

bool UAttachmentSlotComponent::IsSlotEnabled() const {
    return {};
}

bool UAttachmentSlotComponent::IsSlotEmpty() const {
    return {};
}

void UAttachmentSlotComponent::IsParentHeld(bool& IsHeld) const {
}

void UAttachmentSlotComponent::IsAccepts(const FGameplayTag Type, bool& bCanAttach) const {
}

UInventoryItem* UAttachmentSlotComponent::GetParentItem() const {
    return {};
}

