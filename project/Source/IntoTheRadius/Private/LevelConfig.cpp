#include "LevelConfig.h"

#include "ITRDefaults.h"
FLevelConfig::FLevelConfig() {
    bTutorialLevel = {};
    StopGameTimeTick = {};
    ReloadOnTideHappening = {};
    InventoryAllowed = {};
    SleepAllowed = {};
    SaveOnExit = {};
    Autosave = {};
    SaveOnLoad = {};
    MapMaterial = {};
    MapLegendMaterial = {};
    MapScale = {};
    MapRotation = {};
    MaxLevelRadius = {};
    FullPlayerStats = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("LevelTag.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("AllowedGenerators.Min"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AllowedGenerators.Max"), (double)1);
}

FLevelConfig::~FLevelConfig() {
}
