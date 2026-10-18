#include "RadiusShrapnelProjectile.h"
#include "ITRDefaults.h"
#include "RadiusShrapnelComponent.h"

ARadiusShrapnelProjectile::ARadiusShrapnelProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    URadiusShrapnelComponent* Sub0 = Cast<URadiusShrapnelComponent>(GetDefaultSubobjectByName(TEXT("ShrapnelComponent")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<URadiusShrapnelComponent>(TEXT("ShrapnelComponent"));
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bCanEverTick"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bStartWithTickEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickInterval"), (double)0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("ShrapnelComponent"), GetDefaultSubobjectByName(TEXT("ShrapnelComponent")));
}

