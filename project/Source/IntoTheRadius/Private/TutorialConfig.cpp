#include "TutorialConfig.h"

#include "ITRDefaults.h"
FTutorialConfig::FTutorialConfig() {
    PlayerLevel = {};
    Reward = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("TriggerTag.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("LevelTag.TagName"), TEXT("None"));
}
