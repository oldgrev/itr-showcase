#pragma once

#include "CoreMinimal.h"
#include "IPlayFootstepSounds.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIPlayFootstepSounds : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIPlayFootstepSounds {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void StopFootstepLoop();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void StartFootstepLoop();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void PlayFootstepSound();

};
