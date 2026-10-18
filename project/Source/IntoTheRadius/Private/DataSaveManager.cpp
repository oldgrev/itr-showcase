#include "DataSaveManager.h"

UDataSaveManager::UDataSaveManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UDataSaveManager::SetUseAlternateSaveLocation(bool Value) {
}

bool UDataSaveManager::SaveStringToFileEditor(const FString& String, const FString& FilePath, const bool bAppend) {
    return {};
}

bool UDataSaveManager::SaveStringToFile(const FString& String, const FString& FilePath, const bool bAppend) {
    return {};
}

void UDataSaveManager::SaveGameData(UPRGameData* Data, int32 SlotNr, int32 SaveNr) {
}

bool UDataSaveManager::IsSlotWithIronman(const int32 Slot) {
    return {};
}

bool UDataSaveManager::IsSlotEmpty(const FSaveSlotInfo& SlotInfo) {
    return {};
}

bool UDataSaveManager::HasSaves() {
    return {};
}

bool UDataSaveManager::GetUseAlternateSaveLocation() const {
    return {};
}

bool UDataSaveManager::GetSlotInfo(const int32 Slot, FSaveSlotInfo& SlotInfo) {
    return {};
}

FString UDataSaveManager::GetSavesPath() {
    return {};
}

bool UDataSaveManager::GetSaveInfo(const int32 Slot, const int32 Save, FSaveInfo& SaveInfo) {
    return {};
}

FSaveInfo UDataSaveManager::GetLastSaveInfo(FSaveSlotInfo SlotInfo) {
    return {};
}

UDataSaveManager* UDataSaveManager::GetDataSaveManager() {
    return {};
}

FString UDataSaveManager::GetDataPath() {
    return {};
}

bool UDataSaveManager::FixInventoryItemPosition(UInventoryItem* Item) {
    return {};
}

void UDataSaveManager::CopyScopedToAlternateSave() {
}

void UDataSaveManager::CopyAlternateToScopedSave() {
}

void UDataSaveManager::AutosaveGameData(const FString& Message) {
}

