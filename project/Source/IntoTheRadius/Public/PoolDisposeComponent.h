#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PoolDisposeComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UPoolDisposeComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPoolDisposeComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StopTimer();

    UFUNCTION(BlueprintCallable)
    void StartTimerWithDelay(const float Delay);

    UFUNCTION(BlueprintCallable)
    void StartTimer();

    UFUNCTION(BlueprintCallable)
    void Dispose();

protected:
    UPROPERTY(EditDefaultsOnly)
    float DisposeTime;
};
