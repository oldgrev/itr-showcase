#pragma once

#include "CoreMinimal.h"
#include "ICommandEvents.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UICommandEvents : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IICommandEvents {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnWalkCommandStarted();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnWalkCommandFinished();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnIdleCommandStarted();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnIdleCommandFinished();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnAttackCommandStarted();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnAttackCommandFinished();

};
