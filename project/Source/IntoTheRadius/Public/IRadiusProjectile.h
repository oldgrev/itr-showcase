#pragma once

#include "CoreMinimal.h"
#include "IRadiusProjectile.generated.h"

class URadiusProjectileInfo;

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UIRadiusProjectile : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIRadiusProjectile {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    virtual void Launch();

    UFUNCTION(BlueprintCallable)
    virtual void Initialize(URadiusProjectileInfo* ProjectileInfo);

};
