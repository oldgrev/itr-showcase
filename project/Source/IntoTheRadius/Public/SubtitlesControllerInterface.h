#pragma once

#include "CoreMinimal.h"
#include "EPRSubtitleType.h"
#include "SubtitlesControllerInterface.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API USubtitlesControllerInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API ISubtitlesControllerInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void ShowSubtitlesString(const FString& Text, const float& Duration, const EPRSubtitleType& Type, const bool bSwitchable);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void ShowSubtitles(const FText& Text, const float& Duration, const EPRSubtitleType& Type, const bool bSwitchable);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void ShowSaveIcon(bool bAutoSave);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetDressingMode(bool Active);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void HideSubtitles();

};
