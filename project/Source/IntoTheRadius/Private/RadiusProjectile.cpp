#include "RadiusProjectile.h"
#include "ITRDefaults.h"

ARadiusProjectile::ARadiusProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bStartWithTickEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickInterval"), (double)0);
}

void ARadiusProjectile::Dispose() {
}

