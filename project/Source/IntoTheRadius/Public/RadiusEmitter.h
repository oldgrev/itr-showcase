#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IPooledActor.h"
#include "RadiusEmitter.generated.h"

class UParticleSystemComponent;
class UPoolDisposeComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusEmitter : public AActor, public IIPooledActor {
    GENERATED_BODY()
public:
    ARadiusEmitter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    UParticleSystemComponent* GetParticalSystemRef();

protected:
    UPROPERTY(VisibleDefaultsOnly)
    UPoolDisposeComponent* PoolDisposeComponent;
    UPROPERTY(VisibleDefaultsOnly)
    UParticleSystemComponent* ParticleSystemComponent;
    UPROPERTY(VisibleDefaultsOnly)
    FName ReflectionParamaterName;
    UPROPERTY(VisibleDefaultsOnly)
    float DisposeTime;
};
