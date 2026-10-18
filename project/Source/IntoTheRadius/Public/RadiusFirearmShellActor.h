#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IPooledActor.h"
#include "RadiusFirearmShellInfo.h"
#include "RadiusFirearmShellActor.generated.h"

class UPoolDisposeComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusFirearmShellActor : public AActor, public IIPooledActor {
    GENERATED_BODY()
public:
    ARadiusFirearmShellActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintImplementableEvent)
    void Setup(const FRadiusFirearmShellInfo& Info);

protected:
    UPROPERTY(VisibleDefaultsOnly)
    UPoolDisposeComponent* PoolDisposeComponent;
};
