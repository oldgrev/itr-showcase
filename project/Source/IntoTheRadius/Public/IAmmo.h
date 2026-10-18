#pragma once

#include "CoreMinimal.h"
#include "AmmoInfo.h"
#include "IAmmo.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UIAmmo : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIAmmo {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FAmmoInfo GetAmmoInfo() const;

};
