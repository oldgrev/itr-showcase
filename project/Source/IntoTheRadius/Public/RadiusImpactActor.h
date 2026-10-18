#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IPooledActor.h"
#include "RadiusImpactInfo.h"
#include "RadiusImpactActor.generated.h"

class UPoolDisposeComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusImpactActor : public AActor, public IIPooledActor {
    GENERATED_BODY()
public:
    ARadiusImpactActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintImplementableEvent)
    void Setup(const FRadiusImpactInfo& Info);

protected:
    UPROPERTY(VisibleDefaultsOnly)
    UPoolDisposeComponent* PoolDisposeComponent;
};
