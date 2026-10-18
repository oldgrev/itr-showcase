#include "SystemConfig.h"
#include "ITRDefaults.h"

USystemConfig::USystemConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.SystemConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("CommonLevelName"), TEXT("L_Common"));
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionSublevelName"), TEXT("L_Transition"));
    ITRDefaults::Set(GetClass(), this, TEXT("FogFadeTime"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("FogFadeDensityMultiplier"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("TransitionTimeSkipHoursPerSecond"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("DisableFirstLaunchInEditor"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("LevelItemsSpawnBlockExtent.X"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("LevelItemsSpawnBlockExtent.Y"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("LevelItemsSpawnBlockExtent.Z"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("CorpseSpawnBlockExtent.X"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("CorpseSpawnBlockExtent.Y"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("CorpseSpawnBlockExtent.Z"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("DetectorWorkDistance"), (double)500);
    ITRDefaults::Set(GetClass(), this, TEXT("AmmoContainersLockDelay"), (double)0.600000024);
    ITRDefaults::Set(GetClass(), this, TEXT("AmmoContainersLoadingDelay"), (double)0.300000012);
    ITRDefaults::Set(GetClass(), this, TEXT("IngameMenuVerticalShift"), (double)5000);
    ITRDefaults::Set(GetClass(), this, TEXT("FallThroughFloorZ"), (double)-22222);
    ITRDefaults::Set(GetClass(), this, TEXT("DoNotDropItemsFromBackpack"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("BulletsFlyBySoundDistance"), (double)450);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCDiscoverDistance"), (double)450);
    ITRDefaults::Set(GetClass(), this, TEXT("AnomalyDiscoverDistance"), (double)450);
    ITRDefaults::SetNum(GetClass(), this, TEXT("LowLevelGPUs"), 5);
    ITRDefaults::Set(GetClass(), this, TEXT("LowLevelGPUs[0]"), TEXT("970"));
    ITRDefaults::Set(GetClass(), this, TEXT("LowLevelGPUs[1]"), TEXT("1050"));
    ITRDefaults::Set(GetClass(), this, TEXT("LowLevelGPUs[2]"), TEXT("1060"));
    ITRDefaults::Set(GetClass(), this, TEXT("LowLevelGPUs[3]"), TEXT("250"));
    ITRDefaults::Set(GetClass(), this, TEXT("LowLevelGPUs[4]"), TEXT("290"));
    ITRDefaults::SetNum(GetClass(), this, TEXT("HighLevelGPUs"), 3);
    ITRDefaults::Set(GetClass(), this, TEXT("HighLevelGPUs[0]"), TEXT("1080 Ti"));
    ITRDefaults::Set(GetClass(), this, TEXT("HighLevelGPUs[1]"), TEXT("2070"));
    ITRDefaults::Set(GetClass(), this, TEXT("HighLevelGPUs[2]"), TEXT("2080"));
    ITRDefaults::Set(GetClass(), this, TEXT("PlayerPositionAdjustmentInMenu"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("PlayerPositionAdjustmentInTransition"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("bCountEditorAsEarlyAccess"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("ExitIfUnsupportedControllers"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("SteamBetaBranchName"), TEXT("active-beta"));
    ITRDefaults::SetNum(GetClass(), this, TEXT("SteamHideRevisionBranches"), 2);
    ITRDefaults::Set(GetClass(), this, TEXT("SteamHideRevisionBranches[0]"), TEXT("default"));
    ITRDefaults::Set(GetClass(), this, TEXT("SteamHideRevisionBranches[1]"), TEXT("2.0-beta"));
    ITRDefaults::Set(GetClass(), this, TEXT("ClustersSpawnDistance"), (double)100000);
    ITRDefaults::Set(GetClass(), this, TEXT("ClearProfileSavesOnFinalSuicide"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("LevelTransferStepsDelay"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCSpawnMinDistanceFromPlayer"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCSpawnZShift"), (double)90);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCMaxDistanceFromSpawner"), (double)10000);
    ITRDefaults::Set(GetClass(), this, TEXT("NPCSpawnerRestoreRadius"), (double)1000);
    ITRDefaults::Set(GetClass(), this, TEXT("AchievementsConfig.KillDistance"), (double)200);
    ITRDefaults::SetNum(GetClass(), this, TEXT("AchievementsConfig.LoreCassetteTags.GameplayTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("AchievementsConfig.LoreCassetteTags.ParentTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("AchievementsConfig.ArtifactTags.GameplayTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("AchievementsConfig.ArtifactTags.ParentTags"), 0);
    ITRDefaults::Set(GetClass(), this, TEXT("GraphicsPresetLow.GraphicsQuality"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("GraphicsPresetLow.SSR"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("GraphicsPresetMedium.GraphicsQuality"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("GraphicsPresetMedium.SSR"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("GraphicsPresetHigh.GraphicsQuality"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("GraphicsPresetHigh.SSR"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("GraphicsPresetUltra.GraphicsQuality"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("GraphicsPresetUltra.SSR"), true);
}

bool USystemConfig::IsTutorialLevel(const FGameplayTag& LevelTag) const {
    return {};
}

bool USystemConfig::IsLevelTagValid(FGameplayTag LevelTag) const {
    return {};
}

USystemConfig* USystemConfig::GetSystemConfig() {
    return {};
}

FText USystemConfig::GetLevelName(const FGameplayTag& LevelTag, const FText& Placeholder) const {
    return {};
}

void USystemConfig::GetLevelConfig(FGameplayTag LevelTag, FLevelConfig& Config) const {
}

void USystemConfig::GetCurrentLevelConfig(FLevelConfig& Config) const {
}

