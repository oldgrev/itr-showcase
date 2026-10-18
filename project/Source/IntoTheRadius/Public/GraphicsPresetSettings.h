#pragma once

#include "CoreMinimal.h"
#include "EGraphicsSettingsType.h"
#include "ESettingsValue.h"
#include "GraphicsPresetSettings.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FGraphicsPresetSettings {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 GraphicsQuality;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 UpscaleMethod;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 FSRMode;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float UpscaleSharpen;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 Antialiasing;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 FFR;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 VRSS;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool SSR;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float BrightnessAdjustment;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TMap<EGraphicsSettingsType, ESettingsValue> Other;
    FGraphicsPresetSettings();
    ~FGraphicsPresetSettings();
};
