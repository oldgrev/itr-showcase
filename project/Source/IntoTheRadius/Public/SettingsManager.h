#pragma once

#include "CoreMinimal.h"
#include "EGraphicsSettingsType.h"
#include "EPRControllerType.h"
#include "ESettingsValue.h"
#include "IClearable.h"
#include "IPreparable.h"
#include "OnSeatedModeChangedDelegate.h"
#include "OnVignetteChangedDelegate.h"
#include "SettingsManager.generated.h"

class UINIManager;
class USettingsManager;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API USettingsManager : public UObject, public IIPreparable, public IIClearable {
    GENERATED_BODY()
public:
    USettingsManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    int32 TurnType() const;

    UFUNCTION(BlueprintCallable)
    void SetVRSSIndex(const int32 Value) const;

    UFUNCTION(BlueprintCallable)
    void SetVolumeSounds(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void SetVolumeMusic(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void SetVolumeMaster(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void SetVolumeAmbient(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void SetVirtualStock(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetVignetteShown(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetVignetteRunShown(const bool bValue);

    UFUNCTION(BlueprintCallable)
    void SetVestShift(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void SetUpscaleSharpen(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void SetUpscaleMethod(const int32 Value) const;

    UFUNCTION(BlueprintCallable)
    void SetUpdateNoticeShown() const;

    UFUNCTION(BlueprintCallable)
    void SetTurnType(const int32 Value) const;

    UFUNCTION(BlueprintCallable)
    void SetTurnSpeed(float Value) const;

    UFUNCTION(BlueprintPure)
    static FString SettingsValueToString(const ESettingsValue Value);

    UFUNCTION(BlueprintCallable)
    void SetTeleportMovement(bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetSSREnabled(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetShowSubtitles(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetShowBody(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetShowAiDebug(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetSeatedMode(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetPlayerHeight(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void SetNeckHeight(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void SetMovementDirectionType(const int32 Value) const;

    UFUNCTION(BlueprintCallable)
    void SetMirrorHolsters(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetLeftHanded(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetLanguageSetting(const FString Value) const;

    UFUNCTION(BlueprintCallable)
    void SetImperialUnits(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetHoldGrip(bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetHmdDeviceType(const FString Value) const;

    UFUNCTION(BlueprintCallable)
    void SetHighlightDroppedItems(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetGraphicsSetting(const EGraphicsSettingsType Type, const ESettingsValue Value) const;

    UFUNCTION(BlueprintCallable)
    void SetGraphicsQualityIndex(const int32 Value) const;

    UFUNCTION(BlueprintCallable)
    void SetGraphicsPresetIndex(const int32 Value) const;

    UFUNCTION(BlueprintCallable)
    void SetGrabWithTrigger(bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetGPUQualityIndex(const int32 Value) const;

    UFUNCTION(BlueprintCallable)
    void SetFSRMode(const int32 Value) const;

    UFUNCTION(BlueprintCallable)
    void SetFirstLaunch(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetFFRIndex(const int32 Value) const;

    UFUNCTION(BlueprintCallable)
    void SetControllerType(const FString Value) const;

    UFUNCTION(BlueprintCallable)
    void SetControllerShift(const EPRControllerType& Controller, const FVector Value);

    UFUNCTION(BlueprintCallable)
    void SetControllerRotation(const EPRControllerType& Controller, const FRotator Value);

    UFUNCTION(BlueprintCallable)
    void SetBrightnessAdjustment(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void SetBHapticsEnabled(const bool bValue) const;

    UFUNCTION(BlueprintCallable)
    void SetArmLength(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void SetAntialiasingIndex(const int32 Value) const;

    UFUNCTION(BlueprintCallable)
    void SetAimSmoothingIntensity(const float Value) const;

    UFUNCTION(BlueprintCallable)
    void RestoreDefaultControllerRotation(const EPRControllerType& Controller);

    UFUNCTION(BlueprintCallable)
    void ResetGraphicsToDefault(bool bIsMobile);

    UFUNCTION(BlueprintCallable)
    int32 MovementDirectionType() const;

    UFUNCTION(BlueprintCallable)
    bool IsVirtualStock() const;

    UFUNCTION(BlueprintCallable)
    bool IsVignetteShown() const;

    UFUNCTION(BlueprintCallable)
    bool IsVignetteRunShown() const;

    UFUNCTION(BlueprintCallable)
    bool IsTeleportMovement() const;

    UFUNCTION(BlueprintCallable)
    bool IsSSREnabled() const;

    UFUNCTION(BlueprintCallable)
    bool IsShowUpdateNotice() const;

    UFUNCTION(BlueprintCallable)
    bool IsShowSubtitles() const;

    UFUNCTION(BlueprintCallable)
    bool IsShowBody() const;

    UFUNCTION(BlueprintCallable)
    bool IsShowAiDebug() const;

    UFUNCTION(BlueprintCallable)
    bool IsSeatedMode() const;

    UFUNCTION(BlueprintCallable)
    bool IsMirrorHolsters() const;

    UFUNCTION(BlueprintCallable)
    bool IsLeftHanded() const;

    UFUNCTION(BlueprintCallable)
    bool IsImperialUnits() const;

    UFUNCTION(BlueprintCallable)
    bool IsHoldGrip() const;

    UFUNCTION(BlueprintCallable)
    bool IsGrabWithTrigger() const;

    UFUNCTION(BlueprintCallable)
    bool IsFirstLaunch() const;

    UFUNCTION(BlueprintCallable)
    bool IsBHapticsEnabled() const;

    UFUNCTION(BlueprintCallable)
    bool IsAchievementsDisabled() const;

    UFUNCTION(BlueprintPure)
    static FString GraphicsSettingsTypeToString(const EGraphicsSettingsType Value);

    UFUNCTION(BlueprintCallable)
    int32 GetVRSSIndex() const;

    UFUNCTION(BlueprintCallable)
    float GetVolumeSounds() const;

    UFUNCTION(BlueprintCallable)
    float GetVolumeMusic() const;

    UFUNCTION(BlueprintCallable)
    float GetVolumeMaster() const;

    UFUNCTION(BlueprintCallable)
    float GetVolumeAmbient() const;

    UFUNCTION(BlueprintCallable)
    float GetVestShift() const;

    UFUNCTION(BlueprintCallable)
    float GetUpscaleSharpen() const;

    UFUNCTION(BlueprintCallable)
    int32 GetUpscaleMethod() const;

    UFUNCTION(BlueprintCallable)
    float GetTurnSpeed() const;

    UFUNCTION(BlueprintCallable)
    FVector GetTeleportArcRotationForSecondaryGrip() const;

    UFUNCTION(BlueprintPure)
    static USettingsManager* GetSettingsManager();

    UFUNCTION(BlueprintCallable)
    TArray<int32> GetScreenPercentages() const;

    UFUNCTION(BlueprintPure)
    int32 GetScreenPercentage();

    UFUNCTION(BlueprintCallable)
    float GetPlayerHeight() const;

    UFUNCTION(BlueprintPure)
    float GetPixelDensity();

    UFUNCTION(BlueprintCallable)
    float GetNeckHeight() const;

    UFUNCTION(BlueprintCallable)
    FString GetLanguageSetting() const;

    UFUNCTION(BlueprintCallable)
    FString GetHMDDeviceType() const;

    UFUNCTION(BlueprintCallable)
    ESettingsValue GetGraphicsSetting(const EGraphicsSettingsType Type) const;

    UFUNCTION(BlueprintCallable)
    int32 GetGraphicsQualityIndex() const;

    UFUNCTION(BlueprintCallable)
    int32 GetGraphicsPresetIndex() const;

    UFUNCTION(BlueprintCallable)
    int32 GetGPUQualityIndex() const;

    UFUNCTION(BlueprintCallable)
    int32 GetFSRMode() const;

    UFUNCTION(BlueprintCallable)
    int32 GetFFRIndex() const;

    UFUNCTION(BlueprintCallable)
    FString GetControllerType() const;

    UFUNCTION(BlueprintCallable)
    void GetControllerTransform(const EPRControllerType& Controller, FTransform& Left, FTransform& Right) const;

    UFUNCTION(BlueprintCallable)
    FVector GetControllerShift(const EPRControllerType& Controller) const;

    UFUNCTION(BlueprintCallable)
    FRotator GetControllerRotation(const EPRControllerType& Controller) const;

    UFUNCTION(BlueprintCallable)
    float GetBrightnessAdjustment() const;

    UFUNCTION(BlueprintCallable)
    float GetArmLength() const;

    UFUNCTION(BlueprintCallable)
    int32 GetAntialiasingIndex() const;

    UFUNCTION(BlueprintCallable)
    float GetAimSmoothingIntensity() const;

    UFUNCTION(BlueprintCallable)
    bool AreDroppedItemsHighlighted() const;

    UPROPERTY(BlueprintAssignable)
    FOnSeatedModeChanged OnSeatedModeChanged;
    UPROPERTY(BlueprintAssignable)
    FOnVignetteChanged OnVignetteChanged;
    UPROPERTY(BlueprintReadOnly)
    float MaxArmLength;
    UPROPERTY(BlueprintReadOnly)
    float MinArmLength;
private:
    UPROPERTY()
    UINIManager* INIManager;
};
