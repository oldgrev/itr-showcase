#include "RadiusNiagaraEmitter.h"
#include "ITRDefaults.h"
#include "NiagaraComponent.h"
#include "PoolDisposeComponent.h"

ARadiusNiagaraEmitter::ARadiusNiagaraEmitter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UPoolDisposeComponent* Sub0 = Cast<UPoolDisposeComponent>(GetDefaultSubobjectByName(TEXT("PoolDisposeComponent")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UPoolDisposeComponent>(TEXT("PoolDisposeComponent"));
    UNiagaraComponent* Sub1 = Cast<UNiagaraComponent>(GetDefaultSubobjectByName(TEXT("ParticleSystemComponent")));
    if (!Sub1) Sub1 = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ParticleSystemComponent"));
    if (UObject* S = GetDefaultSubobjectByName(TEXT("PoolDisposeComponent"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("DisposeTime"), (double)10);
    }
    if (UObject* S = GetDefaultSubobjectByName(TEXT("ParticleSystemComponent"))) {
        ITRDefaults::SetObject(S->GetClass(), S, TEXT("OverrideParameters.Owner"), GetDefaultSubobjectByName(TEXT("ParticleSystemComponent")));
        ITRDefaults::SetNum(S->GetClass(), S, TEXT("OverrideParameters.SortedParameterOffsets"), 0);
        ITRDefaults::SetNum(S->GetClass(), S, TEXT("OverrideParameters.ParameterData"), 0);
        ITRDefaults::SetNum(S->GetClass(), S, TEXT("OverrideParameters.DataInterfaces"), 0);
        ITRDefaults::SetNum(S->GetClass(), S, TEXT("OverrideParameters.UObjects"), 0);
    }
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bCanEverTick"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bStartWithTickEnabled"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickInterval"), (double)0);
    ITRDefaults::SetObject(GetClass(), this, TEXT("PoolDisposeComponent"), GetDefaultSubobjectByName(TEXT("PoolDisposeComponent")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("ParticleSystemComponent"), GetDefaultSubobjectByName(TEXT("ParticleSystemComponent")));
    ITRDefaults::Set(GetClass(), this, TEXT("DisposeTime"), (double)10);
}

