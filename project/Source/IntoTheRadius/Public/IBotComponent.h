#pragma once

#include "CoreMinimal.h"
#include "IBotComponent.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UIBotComponent : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIBotComponent {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OwnerInitialized();

};
