#include "GraphicsPresetSettings.h"

#include "ITRDefaults.h"
FGraphicsPresetSettings::FGraphicsPresetSettings() {
    GraphicsQuality = {};
    UpscaleMethod = {};
    FSRMode = {};
    UpscaleSharpen = {};
    Antialiasing = {};
    FFR = {};
    VRSS = {};
    SSR = {};
    BrightnessAdjustment = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("GraphicsQuality"), (double)2);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SSR"), true);
}

FGraphicsPresetSettings::~FGraphicsPresetSettings() {
}
