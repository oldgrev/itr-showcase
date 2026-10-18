#pragma once

#include "CoreMinimal.h"
#include "DebugAndCheats.generated.h"

class APawn;

UINTERFACE(MinimalAPI, Blueprintable)
class UDebugAndCheats : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IDebugAndCheats {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SwitchCheatInvisibility();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SwitchCheatGodMode();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetDebugAIPawn(APawn* Pawn);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetCheatInvisibility(bool bValue);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetCheatGodMode(bool bValue);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetCheatSpeed(bool& Value);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    bool GetCheatInvisibility();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    bool GetCheatGodMode();

};
