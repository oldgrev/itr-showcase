#include "MissionBaseConfig.h"
#include "ITRDefaults.h"

UMissionBaseConfig::UMissionBaseConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.MissionBaseConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("ID.TagName"), TEXT("None"));
}

