#include "LevelManager.h"

ULevelManager::ULevelManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void ULevelManager::UnloadSublevel(const FName& SublevelName) {
}

void ULevelManager::UnloadLevel(const FGameplayTag LevelTag) {
}

void ULevelManager::UnloadAll() {
}

void ULevelManager::ShowSublevel(const FName& SublevelName) {
}

void ULevelManager::OnUnloadingTick() {
}

void ULevelManager::OnLoadingTick() {
}

void ULevelManager::LoadSublevel(const FName& SublevelName) {
}

void ULevelManager::LoadLevel(const FGameplayTag LevelTag) {
}

bool ULevelManager::IsReady() const {
    return {};
}

void ULevelManager::HideSublevel(const FName& SublevelName, const bool bKeepLoaded) {
}

ULevelManager* ULevelManager::GetLevelManager() {
    return {};
}

