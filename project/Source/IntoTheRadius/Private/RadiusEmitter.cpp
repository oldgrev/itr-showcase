#include "RadiusEmitter.h"
#include "ITRDefaults.h"
#include "Particles/ParticleSystemComponent.h"
#include "PoolDisposeComponent.h"

ARadiusEmitter::ARadiusEmitter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UParticleSystemComponent* Sub0 = Cast<UParticleSystemComponent>(GetDefaultSubobjectByName(TEXT("ParticleSystemComponent")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
    UPoolDisposeComponent* Sub1 = Cast<UPoolDisposeComponent>(GetDefaultSubobjectByName(TEXT("PoolDisposeComponent")));
    if (!Sub1) Sub1 = CreateDefaultSubobject<UPoolDisposeComponent>(TEXT("PoolDisposeComponent"));
    if (UObject* S = GetDefaultSubobjectByName(TEXT("PoolDisposeComponent"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("DisposeTime"), (double)10);
    }
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bCanEverTick"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickInterval"), (double)0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("RootComponent"), GetDefaultSubobjectByName(TEXT("ParticleSystemComponent")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("PoolDisposeComponent"), GetDefaultSubobjectByName(TEXT("PoolDisposeComponent")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("ParticleSystemComponent"), GetDefaultSubobjectByName(TEXT("ParticleSystemComponent")));
    ITRDefaults::Set(GetClass(), this, TEXT("ReflectionParamaterName"), TEXT("ReflectedParticles"));
    ITRDefaults::Set(GetClass(), this, TEXT("DisposeTime"), (double)10);
}

UParticleSystemComponent* ARadiusEmitter::GetParticalSystemRef() {
    return {};
}

