#include "PRGameInstance.h"

UPRGameInstance::UPRGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UPRGameInstance::SetShutdown() {
    return {};
}

void UPRGameInstance::RestartGame(const int32 Slot, const bool skipTutorial, const bool Ironman, const FRadiusGameDifficulty Difficulty) {
}

bool UPRGameInstance::IsEAPlayer() {
    return {};
}

bool UPRGameInstance::IsBetaPlayer() const {
    return {};
}

FString UPRGameInstance::HmdToString(EPRHmdDeviceType HMD) {
    return {};
}

bool UPRGameInstance::HideVersionRevision() const {
    return {};
}

bool UPRGameInstance::HasSupporterPack() const {
    return {};
}

void UPRGameInstance::HasSaveOnStartup(bool& hasSave) {
}

bool UPRGameInstance::GetPurchaseDate(FDateTime& PurchaseDate, FString& PurchaseDateString) {
    return {};
}

void UPRGameInstance::GetPlayerID(FString& ID) {
}

void UPRGameInstance::GetPlayerCountry(FString& countryCode) {
}

void UPRGameInstance::GetHMDDeviceType(EPRHmdDeviceType& HMD) {
}

void UPRGameInstance::GetDeviceTypeString(FString& HMD, FString& Controller) {
}

void UPRGameInstance::GetControllerType(EPRControllerType& Controller, bool& bIsDefault) {
}

void UPRGameInstance::FixTutorialSaveLevel() {
}

void UPRGameInstance::DoStart() {
}

FString UPRGameInstance::ControllerToString(EPRControllerType Controller) {
    return {};
}

void UPRGameInstance::ConfigureSentrySubsystem_Delegate(UObject* Settings) const {
}

