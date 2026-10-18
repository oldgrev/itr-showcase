#include "PREnvironment.h"
#include "ITRDefaults.h"

APREnvironment::APREnvironment(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("EnvironmentLevelTag.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("DebugTimeScale"), (double)1);
}

void APREnvironment::Startup() {
}

void APREnvironment::SetEnvironmentHidden(const bool bEnvironmentHidden) {
}

void APREnvironment::OnGameTimeChanged(float AddedSeconds) {
}

void APREnvironment::OnGameplayTimeDilationChanged(float Dilation) {
}

FVector APREnvironment::GetRadiusLocation() const {
    return {};
}

