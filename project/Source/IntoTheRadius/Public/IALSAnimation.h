#pragma once

#include "CoreMinimal.h"
#include "EGroundedEntryState.h"
#include "IALSAnimation.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIALSAnimation : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIALSAnimation {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetOverlayOverrideState(int32 NewOverlayOverrideState);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetGroundedEntryState(EGroundedEntryState NewGroundedEntryState);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ReloadWeapon();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnJumped();

};
