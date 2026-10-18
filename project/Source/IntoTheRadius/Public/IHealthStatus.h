#pragma once

#include "CoreMinimal.h"
#include "IHealthStatus.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIHealthStatus : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIHealthStatus {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsAlive();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetHealthPercent(float& HealthPercent);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetHealth(float& Health);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ChangeHealth(float HealthDelta);

};
