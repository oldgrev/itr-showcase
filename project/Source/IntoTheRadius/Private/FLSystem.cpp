#include "FLSystem.h"

UFLSystem::UFLSystem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UFLSystem::IsSimulate() {
    return {};
}

bool UFLSystem::IsShippingBuild() {
    return {};
}

bool UFLSystem::IsQABuild() {
    return {};
}

bool UFLSystem::IsModKitBuild() {
    return {};
}

bool UFLSystem::IsEditor() {
    return {};
}

bool UFLSystem::IsDevelopmentBuild() {
    return {};
}

bool UFLSystem::IsBuild() {
    return {};
}

FString UFLSystem::GetRelevantLanguage() {
    return {};
}

void UFLSystem::GetPuTimers(float& RawFrameTime, float& RawGameThreadTime, float& RawrenderThreadTime, float& RawGPUFrameTime) {
}

FString UFLSystem::GetProjectVersion() {
    return {};
}

FString UFLSystem::GetProjectRevision() {
    return {};
}

FString UFLSystem::GetProjectBeta() {
    return {};
}

FString UFLSystem::GetInstallID() {
    return {};
}

FString UFLSystem::GetFullVersionString() {
    return {};
}

FString UFLSystem::GetClientVersionString() {
    return {};
}

