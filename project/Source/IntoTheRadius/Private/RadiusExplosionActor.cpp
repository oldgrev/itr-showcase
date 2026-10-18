#include "RadiusExplosionActor.h"
#include "ITRDefaults.h"

ARadiusExplosionActor::ARadiusExplosionActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bCanEverTick"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickInterval"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxIteration"), (double)4);
    ITRDefaults::Set(GetClass(), this, TEXT("Strength"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxWallDistance"), (double)500);
    ITRDefaults::Set(GetClass(), this, TEXT("TraceProfileName"), TEXT("Bullet"));
    ITRDefaults::Set(GetClass(), this, TEXT("DamageMinRange"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxDamageScale"), (double)0.300000012);
    ITRDefaults::Set(GetClass(), this, TEXT("HitMinDistance"), (double)300);
    ITRDefaults::Set(GetClass(), this, TEXT("ExplosionRadius"), (double)1500);
    ITRDefaults::Set(GetClass(), this, TEXT("WallScaleIn.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("WallScaleIn.Y"), (double)4);
    ITRDefaults::Set(GetClass(), this, TEXT("WallScaleOut.X"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("WallScaleOut.Y"), (double)0.699999988);
    ITRDefaults::Set(GetClass(), this, TEXT("WallRangeMin"), (double)1);
}

const FExplosionInfo& ARadiusExplosionActor::GetExplosionInfo() const {
    static FExplosionInfo Dummy;
    return Dummy;
}

