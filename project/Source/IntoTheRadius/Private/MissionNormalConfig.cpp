#include "MissionNormalConfig.h"
#include "ITRDefaults.h"

UMissionNormalConfig::UMissionNormalConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.MissionNormalConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("CooldownMissions"), (double)1);
}

bool UMissionNormalConfig::CheckObjectives() {
    return {};
}

