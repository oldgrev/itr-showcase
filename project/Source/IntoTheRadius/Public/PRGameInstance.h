#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EPRControllerType.h"
#include "EPRHmdDeviceType.h"
#include "EStartupType.h"
#include "PRGIReferences.h"
#include "RadiusGameDifficulty.h"
#include "RadiusGameInstanceInterface.h"
#include "PRGameInstance.generated.h"

class UAnalyticsManager;
class UObject;
class UTextureRenderTarget2D;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPRGameInstance : public UPRGIReferences, public IRadiusGameInstanceInterface {
    GENERATED_BODY()
public:
    UPRGameInstance(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    bool SetShutdown();

    UFUNCTION(BlueprintCallable)
    void RestartGame(const int32 Slot, const bool skipTutorial, const bool Ironman, const FRadiusGameDifficulty Difficulty);

    UFUNCTION(BlueprintImplementableEvent)
    void ReceiveOnGameStart();

    UFUNCTION(BlueprintImplementableEvent)
    void OnShutdown();

    UFUNCTION(BlueprintImplementableEvent)
    void OnBeforeLoad();

public:
    UFUNCTION(BlueprintPure)
    bool IsEAPlayer();

    UFUNCTION(BlueprintCallable)
    bool IsBetaPlayer() const;

    UFUNCTION(BlueprintPure)
    FString HmdToString(EPRHmdDeviceType HMD);

    UFUNCTION(BlueprintCallable)
    bool HideVersionRevision() const;

    UFUNCTION(BlueprintCallable)
    bool HasSupporterPack() const;

    UFUNCTION(BlueprintPure)
    void HasSaveOnStartup(bool& hasSave);

    UFUNCTION(BlueprintPure)
    bool GetPurchaseDate(FDateTime& PurchaseDate, FString& PurchaseDateString);

    UFUNCTION(BlueprintPure)
    void GetPlayerID(FString& ID);

    UFUNCTION(BlueprintPure)
    void GetPlayerCountry(FString& countryCode);

    UFUNCTION(BlueprintPure)
    void GetHMDDeviceType(EPRHmdDeviceType& HMD);

    UFUNCTION(BlueprintCallable)
    void GetDeviceTypeString(FString& HMD, FString& Controller);

    UFUNCTION(BlueprintPure)
    void GetControllerType(EPRControllerType& Controller, bool& bIsDefault);

    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    UAnalyticsManager* GetAnalyticsManager();

protected:
    UFUNCTION(BlueprintCallable)
    void FixTutorialSaveLevel();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void ExitGameBP(const bool bMenu, const bool bSave);

private:
    UFUNCTION()
    void DoStart();

public:
    UFUNCTION(BlueprintPure)
    FString ControllerToString(EPRControllerType Controller);

private:
    UFUNCTION()
    void ConfigureSentrySubsystem_Delegate(UObject* Settings) const;

public:
    UPROPERTY(BlueprintReadOnly)
    EStartupType StartupType;
    UPROPERTY(BlueprintReadOnly)
    FString StartupLevelName;
    UPROPERTY()
    TMap<FGameplayTag, UTextureRenderTarget2D*> MapsRTs;
};
