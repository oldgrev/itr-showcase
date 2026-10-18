#pragma once

#include "CoreMinimal.h"
#include "ExplosionInfo.h"
#include "IRadiusExplosionActor.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIRadiusExplosionActor : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIRadiusExplosionActor {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void Launch();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void Initialize(const FExplosionInfo& ExplosionInfo);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void Dispose();

};
