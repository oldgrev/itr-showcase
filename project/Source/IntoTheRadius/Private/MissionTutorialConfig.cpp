#include "MissionTutorialConfig.h"
#include "ITRDefaults.h"

UMissionTutorialConfig::UMissionTutorialConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.MissionTutorialConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("AutoProgress"), true);
}

