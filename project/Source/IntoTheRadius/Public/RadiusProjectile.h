#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IPooledActor.h"
#include "IRadiusProjectile.h"
#include "RadiusProjectile.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusProjectile : public AActor, public IIRadiusProjectile, public IIPooledActor {
    GENERATED_BODY()
public:
    ARadiusProjectile(const FObjectInitializer& ObjectInitializer);

    UFUNCTION()
    void Dispose();

protected:
    UPROPERTY(EditDefaultsOnly)
    float AutoDisposeTime;
    UPROPERTY(EditDefaultsOnly)
    float DamageDisposeTime;
};
