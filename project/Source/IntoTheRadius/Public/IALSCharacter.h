#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "EGait.h"
#include "EMovementAction.h"
#include "EMovementState.h"
#include "EOverlayState.h"
#include "ERotationMode.h"
#include "EStance.h"
#include "EViewMode.h"
#include "IALSCharacter.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIALSCharacter : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIALSCharacter {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetViewMode(EViewMode ViewMode);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetStance(EStance NewStance);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetRotationMode(ERotationMode NewRotationMode);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetOverlayState(EOverlayState NewOverLayState);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetMovementState(EMovementState NewMovementState);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetMovementAction(EMovementAction NewMovementAction);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetGait(EGait NewGait);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetEssentialValues(FVector& OutVelocity, FVector& OutAcceleration, FVector& OutMovementInput, bool& OutIsMoving, bool& OutHasMovementInput, float& OutSpeed, float& OutMovementInputAmount, FRotator& OutRotator, float& OutAimYawRate);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetCurrentStates(TEnumAsByte<EMovementMode>& OutPawnMovementMode, EMovementState& OutMovementState, EMovementState& OutPrevMovementState, EMovementAction& OutMovementAction, ERotationMode& OutRotationMode, EGait& OutActualGait, EStance& OutActualStance, EViewMode& OutViewMode, EOverlayState& OutOverlayState);

};
