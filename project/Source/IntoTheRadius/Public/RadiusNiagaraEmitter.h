#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IPooledActor.h"
#include "RadiusNiagaraEmitter.generated.h"

class UNiagaraComponent;
class UPoolDisposeComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusNiagaraEmitter : public AActor, public IIPooledActor {
    GENERATED_BODY()
public:
    ARadiusNiagaraEmitter(const FObjectInitializer& ObjectInitializer);

protected:
    UPROPERTY(VisibleDefaultsOnly)
    UPoolDisposeComponent* PoolDisposeComponent;
    UPROPERTY(VisibleDefaultsOnly)
    UNiagaraComponent* ParticleSystemComponent;
    UPROPERTY(VisibleDefaultsOnly)
    float DisposeTime;
};
