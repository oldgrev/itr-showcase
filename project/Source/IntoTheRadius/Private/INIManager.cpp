#include "INIManager.h"

UINIManager::UINIManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UINIManager::TrySetVector(const FString& Filename, const FString& Section, const FString& Key, const FVector Value) {
    return {};
}

bool UINIManager::TrySetString(const FString& Filename, const FString& Section, const FString& Key, const FString& Value) {
    return {};
}

bool UINIManager::TrySetInt(const FString& Filename, const FString& Section, const FString& Key, const int32 Value) {
    return {};
}

bool UINIManager::TrySetFloat(const FString& Filename, const FString& Section, const FString& Key, const float Value) {
    return {};
}

bool UINIManager::TrySetBool(const FString& Filename, const FString& Section, const FString& Key, const bool bValue) {
    return {};
}

FVector UINIManager::TryGetVector(const FString& Filename, const FString& Section, const FString& Key) {
    return {};
}

FString UINIManager::TryGetString(const FString& Filename, const FString& Section, const FString& Key) {
    return {};
}

int32 UINIManager::TryGetInt(const FString& Filename, const FString& Section, const FString& Key) {
    return {};
}

float UINIManager::TryGetFloat(const FString& Filename, const FString& Section, const FString& Key) {
    return {};
}

bool UINIManager::TryGetBool(const FString& Filename, const FString& Section, const FString& Key) {
    return {};
}

void UINIManager::StoreInUserSave(const FString& Filename) {
}

FString UINIManager::GetStringSilent(const FString& Filename, const FString& Section, const FString& Key) {
    return {};
}

UINIManager* UINIManager::GetINIManager() {
    return {};
}

float UINIManager::GetFloatSilent(const FString& Filename, const FString& Section, const FString& Key) {
    return {};
}

bool UINIManager::GetBoolSilent(const FString& Filename, const FString& Section, const FString& Key) {
    return {};
}

bool UINIManager::Exists(const FString& Filename, const FString& Section, const FString& Key) {
    return {};
}

