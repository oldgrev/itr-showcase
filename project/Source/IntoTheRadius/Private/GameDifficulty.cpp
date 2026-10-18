#include "GameDifficulty.h"

#include "ITRDefaults.h"
FGameDifficulty::FGameDifficulty() {
    SleepRestoreHealth = {};
    LocationOnMap = {};
    EnemySense = {};
    ShowTracers = {};
    ShowTips = {};
    ItemsDropType = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("EnemySense"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemsDropType"), (double)1);
}
