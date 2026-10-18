#include "RadiusGameDifficulty.h"

#include "ITRDefaults.h"
FRadiusGameDifficulty::FRadiusGameDifficulty() {
    SleepRestoreHealth = {};
    LocationOnMap = {};
    ShowTips = {};
    Hunger = {};
    EnemySense = {};
    EnemyHealth = {};
    EnemyDamage = {};
    EnemyCount = {};
    ItemsDropType = {};
    ItemSellPrice = {};
    WeaponShotDamage = {};
    AnomalyDamage = {};
    AnomalyAmount = {};
    ShowTracers = {};
    MissionMoneyReward = {};
    TideTime = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Hunger"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("EnemySense"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("EnemyHealth"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("EnemyDamage"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("EnemyCount"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemsDropType"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemSellPrice"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("WeaponShotDamage"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AnomalyDamage"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AnomalyAmount"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MissionMoneyReward"), (double)30);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TideTime"), (double)30);
}
