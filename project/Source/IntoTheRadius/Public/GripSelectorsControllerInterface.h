#pragma once

#include "CoreMinimal.h"
#include "EPRHand.h"
#include "GripSelectorsControllerInterface.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UGripSelectorsControllerInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IGripSelectorsControllerInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void ShowSelector(EPRHand hand, bool Distance);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void HideSelector(EPRHand hand);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void HideAllSelectors();

};
