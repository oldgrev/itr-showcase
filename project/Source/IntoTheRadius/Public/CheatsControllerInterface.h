#pragma once

#include "CoreMinimal.h"
#include "CheatsControllerInterface.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UCheatsControllerInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API ICheatsControllerInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool SwitchPlayerCollisions() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool SwitchCheatShowStashes();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool SwitchCheatShowCorpses();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool SwitchCheatShowArtifacts();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SwitchCheatNoClip();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool SwitchCheatHasSupporterPack();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetCheatScreenshot(const bool bValue);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetCheatReload(const bool bValue);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetCheatPause(const bool bValue);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetCheatNoRandom(const bool bValue);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetCheatHasSupporterPack(const bool bValue);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GetCheatShowStashes() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GetCheatShowCorpses() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GetCheatShowArtifacts() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GetCheatScreenshot() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GetCheatReload() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GetCheatPause() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GetCheatNoRandom() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GetCheatNoClip() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GetCheatHasSupporterPack() const;

};
