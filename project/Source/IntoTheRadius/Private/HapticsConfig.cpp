#include "HapticsConfig.h"
#include "ITRDefaults.h"

UHapticsConfig::UHapticsConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.HapticsConfig"));
}

void UHapticsConfig::StopHaptics() {
}

void UHapticsConfig::PlayRecoilHaptics(const bool bLeftHand, const bool bSecondaryGripped, const float PowerAlpha) {
}

void UHapticsConfig::PlayHapticsWithRotation(const EHapticsType Type, const float angleX, const float OffsetY) {
}

void UHapticsConfig::PlayHaptics(const EHapticsType Type) {
}

bool UHapticsConfig::IsHapticsEnabled() {
    return {};
}

UHapticsConfig* UHapticsConfig::GetHapticsConfig() {
    return {};
}

