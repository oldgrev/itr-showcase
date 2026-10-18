#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "AIEdPerceptionComp.generated.h"

UCLASS(Blueprintable, BlueprintType, Config=Game, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UAIEdPerceptionComp : public UAIPerceptionComponent {
    GENERATED_BODY()
public:
    UAIEdPerceptionComp(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool SetSightHalfAngle(float HalfAngle);

    UFUNCTION(BlueprintCallable)
    bool SetSightDistance(float Distance);

    UFUNCTION(BlueprintCallable)
    bool SetHearingDistance(float Distance);

    UFUNCTION(BlueprintPure)
    float GetSightHalfAngle();

    UFUNCTION(BlueprintPure)
    float GetSightDistance();

    UFUNCTION(BlueprintPure)
    float GetHearingDistance();

};
