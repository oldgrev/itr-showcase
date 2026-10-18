#pragma once

#include "CoreMinimal.h"
#include "EPRControllerType.h"
#include "IPRPlayerController.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UIPRPlayerController : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIPRPlayerController {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    bool IsAllInputBlocked();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void InitControlScheme();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    EPRControllerType GetControllerType();

};
