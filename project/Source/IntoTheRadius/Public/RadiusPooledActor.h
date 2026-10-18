#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IPooledActor.h"
#include "RadiusPooledActor.generated.h"

class UPoolDisposeComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusPooledActor : public AActor, public IIPooledActor {
    GENERATED_BODY()
public:
    ARadiusPooledActor(const FObjectInitializer& ObjectInitializer);

protected:
    UPROPERTY(VisibleDefaultsOnly)
    UPoolDisposeComponent* PoolDisposeComponent;
    UPROPERTY(VisibleDefaultsOnly)
    bool bExcludedFromPool;
};
