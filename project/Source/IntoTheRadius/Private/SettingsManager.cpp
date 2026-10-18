#include "SettingsManager.h"
#include "ITRDefaults.h"

USettingsManager::USettingsManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("MaxArmLength"), (double)80);
    ITRDefaults::Set(GetClass(), this, TEXT("MinArmLength"), (double)40);
}

int32 USettingsManager::TurnType() const {
    return {};
}

void USettingsManager::SetVRSSIndex(const int32 Value) const {
}

void USettingsManager::SetVolumeSounds(const float Value) const {
}

void USettingsManager::SetVolumeMusic(const float Value) const {
}

void USettingsManager::SetVolumeMaster(const float Value) const {
}

void USettingsManager::SetVolumeAmbient(const float Value) const {
}

void USettingsManager::SetVirtualStock(const bool bValue) const {
}

void USettingsManager::SetVignetteShown(const bool bValue) const {
}

void USettingsManager::SetVignetteRunShown(const bool bValue) {
}

void USettingsManager::SetVestShift(const float Value) const {
}

void USettingsManager::SetUpscaleSharpen(const float Value) const {
}

void USettingsManager::SetUpscaleMethod(const int32 Value) const {
}

void USettingsManager::SetUpdateNoticeShown() const {
}

void USettingsManager::SetTurnType(const int32 Value) const {
}

void USettingsManager::SetTurnSpeed(float Value) const {
}

FString USettingsManager::SettingsValueToString(const ESettingsValue Value) {
    return {};
}

void USettingsManager::SetTeleportMovement(bool bValue) const {
}

void USettingsManager::SetSSREnabled(const bool bValue) const {
}

void USettingsManager::SetShowSubtitles(const bool bValue) const {
}

void USettingsManager::SetShowBody(const bool bValue) const {
}

void USettingsManager::SetShowAiDebug(const bool bValue) const {
}

void USettingsManager::SetSeatedMode(const bool bValue) const {
}

void USettingsManager::SetPlayerHeight(const float Value) const {
}

void USettingsManager::SetNeckHeight(const float Value) const {
}

void USettingsManager::SetMovementDirectionType(const int32 Value) const {
}

void USettingsManager::SetMirrorHolsters(const bool bValue) const {
}

void USettingsManager::SetLeftHanded(const bool bValue) const {
}

void USettingsManager::SetLanguageSetting(const FString Value) const {
}

void USettingsManager::SetImperialUnits(const bool bValue) const {
}

void USettingsManager::SetHoldGrip(bool bValue) const {
}

void USettingsManager::SetHmdDeviceType(const FString Value) const {
}

void USettingsManager::SetHighlightDroppedItems(const bool bValue) const {
}

void USettingsManager::SetGraphicsSetting(const EGraphicsSettingsType Type, const ESettingsValue Value) const {
}

void USettingsManager::SetGraphicsQualityIndex(const int32 Value) const {
}

void USettingsManager::SetGraphicsPresetIndex(const int32 Value) const {
}

void USettingsManager::SetGrabWithTrigger(bool bValue) const {
}

void USettingsManager::SetGPUQualityIndex(const int32 Value) const {
}

void USettingsManager::SetFSRMode(const int32 Value) const {
}

void USettingsManager::SetFirstLaunch(const bool bValue) const {
}

void USettingsManager::SetFFRIndex(const int32 Value) const {
}

void USettingsManager::SetControllerType(const FString Value) const {
}

void USettingsManager::SetControllerShift(const EPRControllerType& Controller, const FVector Value) {
}

void USettingsManager::SetControllerRotation(const EPRControllerType& Controller, const FRotator Value) {
}

void USettingsManager::SetBrightnessAdjustment(const float Value) const {
}

void USettingsManager::SetBHapticsEnabled(const bool bValue) const {
}

void USettingsManager::SetArmLength(const float Value) const {
}

void USettingsManager::SetAntialiasingIndex(const int32 Value) const {
}

void USettingsManager::SetAimSmoothingIntensity(const float Value) const {
}

void USettingsManager::RestoreDefaultControllerRotation(const EPRControllerType& Controller) {
}

void USettingsManager::ResetGraphicsToDefault(bool bIsMobile) {
}

int32 USettingsManager::MovementDirectionType() const {
    return {};
}

bool USettingsManager::IsVirtualStock() const {
    return {};
}

bool USettingsManager::IsVignetteShown() const {
    return {};
}

bool USettingsManager::IsVignetteRunShown() const {
    return {};
}

bool USettingsManager::IsTeleportMovement() const {
    return {};
}

bool USettingsManager::IsSSREnabled() const {
    return {};
}

bool USettingsManager::IsShowUpdateNotice() const {
    return {};
}

bool USettingsManager::IsShowSubtitles() const {
    return {};
}

bool USettingsManager::IsShowBody() const {
    return {};
}

bool USettingsManager::IsShowAiDebug() const {
    return {};
}

bool USettingsManager::IsSeatedMode() const {
    return {};
}

bool USettingsManager::IsMirrorHolsters() const {
    return {};
}

bool USettingsManager::IsLeftHanded() const {
    return {};
}

bool USettingsManager::IsImperialUnits() const {
    return {};
}

bool USettingsManager::IsHoldGrip() const {
    return {};
}

bool USettingsManager::IsGrabWithTrigger() const {
    return {};
}

bool USettingsManager::IsFirstLaunch() const {
    return {};
}

bool USettingsManager::IsBHapticsEnabled() const {
    return {};
}

bool USettingsManager::IsAchievementsDisabled() const {
    return {};
}

FString USettingsManager::GraphicsSettingsTypeToString(const EGraphicsSettingsType Value) {
    return {};
}

int32 USettingsManager::GetVRSSIndex() const {
    return {};
}

float USettingsManager::GetVolumeSounds() const {
    return {};
}

float USettingsManager::GetVolumeMusic() const {
    return {};
}

float USettingsManager::GetVolumeMaster() const {
    return {};
}

float USettingsManager::GetVolumeAmbient() const {
    return {};
}

float USettingsManager::GetVestShift() const {
    return {};
}

float USettingsManager::GetUpscaleSharpen() const {
    return {};
}

int32 USettingsManager::GetUpscaleMethod() const {
    return {};
}

float USettingsManager::GetTurnSpeed() const {
    return {};
}

FVector USettingsManager::GetTeleportArcRotationForSecondaryGrip() const {
    return {};
}

USettingsManager* USettingsManager::GetSettingsManager() {
    return {};
}

TArray<int32> USettingsManager::GetScreenPercentages() const {
    return {};
}

int32 USettingsManager::GetScreenPercentage() {
    return {};
}

float USettingsManager::GetPlayerHeight() const {
    return {};
}

float USettingsManager::GetPixelDensity() {
    return {};
}

float USettingsManager::GetNeckHeight() const {
    return {};
}

FString USettingsManager::GetLanguageSetting() const {
    return {};
}

FString USettingsManager::GetHMDDeviceType() const {
    return {};
}

ESettingsValue USettingsManager::GetGraphicsSetting(const EGraphicsSettingsType Type) const {
    return {};
}

int32 USettingsManager::GetGraphicsQualityIndex() const {
    return {};
}

int32 USettingsManager::GetGraphicsPresetIndex() const {
    return {};
}

int32 USettingsManager::GetGPUQualityIndex() const {
    return {};
}

int32 USettingsManager::GetFSRMode() const {
    return {};
}

int32 USettingsManager::GetFFRIndex() const {
    return {};
}

FString USettingsManager::GetControllerType() const {
    return {};
}

void USettingsManager::GetControllerTransform(const EPRControllerType& Controller, FTransform& Left, FTransform& Right) const {
}

FVector USettingsManager::GetControllerShift(const EPRControllerType& Controller) const {
    return {};
}

FRotator USettingsManager::GetControllerRotation(const EPRControllerType& Controller) const {
    return {};
}

float USettingsManager::GetBrightnessAdjustment() const {
    return {};
}

float USettingsManager::GetArmLength() const {
    return {};
}

int32 USettingsManager::GetAntialiasingIndex() const {
    return {};
}

float USettingsManager::GetAimSmoothingIntensity() const {
    return {};
}

bool USettingsManager::AreDroppedItemsHighlighted() const {
    return {};
}

