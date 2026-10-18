#pragma once

#include "CoreMinimal.h"
#include "ActorVolumeActivationInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UActorVolumeActivationInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IActorVolumeActivationInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetVolumeActivationState(bool NewState);

};
