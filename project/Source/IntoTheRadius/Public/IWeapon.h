#pragma once

#include "CoreMinimal.h"
#include "WeaponInfo.h"
#include "IWeapon.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UIWeapon : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIWeapon {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsSmoothingScriptOn();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FWeaponInfo GetWeaponInfo() const;

};
