#include "TeleportPointInfo.h"

#include "ITRDefaults.h"
FTeleportPointInfo::FTeleportPointInfo() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.FaceIndex"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.Time"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.Distance"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.ImpactPoint.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.ImpactPoint.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.ImpactPoint.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.Normal.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.Normal.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.Normal.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.ImpactNormal.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.ImpactNormal.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.ImpactNormal.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.TraceStart.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.TraceStart.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.TraceStart.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.TraceEnd.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.TraceEnd.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.TraceEnd.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.PenetrationDepth"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.Item"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.ElementIndex"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.bBlockingHit"), false);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.bStartPenetrating"), false);
    ITRDefaults::SetObject(StaticStruct(), this, TEXT("HitResult.PhysMaterial"), nullptr);
    ITRDefaults::SetObject(StaticStruct(), this, TEXT("HitResult.Actor"), nullptr);
    ITRDefaults::SetObject(StaticStruct(), this, TEXT("HitResult.Component"), nullptr);
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.BoneName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("HitResult.MyBoneName"), TEXT("None"));
}
