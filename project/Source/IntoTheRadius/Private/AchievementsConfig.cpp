#include "AchievementsConfig.h"

#include "ITRDefaults.h"
FAchievementsConfig::FAchievementsConfig() {
    KillDistance = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("KillDistance"), (double)200);
    ITRDefaults::SetNum(StaticStruct(), this, TEXT("LoreCassetteTags.GameplayTags"), 0);
    ITRDefaults::SetNum(StaticStruct(), this, TEXT("LoreCassetteTags.ParentTags"), 0);
    ITRDefaults::SetNum(StaticStruct(), this, TEXT("ArtifactTags.GameplayTags"), 0);
    ITRDefaults::SetNum(StaticStruct(), this, TEXT("ArtifactTags.ParentTags"), 0);
}

FAchievementsConfig::~FAchievementsConfig() {
}
