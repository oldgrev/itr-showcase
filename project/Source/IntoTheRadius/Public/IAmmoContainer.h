#pragma once

#include "CoreMinimal.h"
#include "AmmoContainerData.h"
#include "PRAmmoContainerInfo.h"
#include "IAmmoContainer.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UIAmmoContainer : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIAmmoContainer {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetLoadingLock(bool lock);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnAmmoRemoved();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnAmmoAdded();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsLoadingLocked() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetAmmoContainerInfo(FPRAmmoContainerInfo& Info);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetAmmoContainerData(FAmmoContainerData& Data);

};
