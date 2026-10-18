#include "PRLootEntryConfig.h"

#include "ITRDefaults.h"
FPRLootEntryConfig::FPRLootEntryConfig() {
    LootPoints = {};
    RandomizeDurability = {};
    ChangeLootPointsFromDurability = {};
    RandomizeAmmo = {};
    ChangeLootPointsFromAmmo = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ItemTag.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("RandomDurability.Min"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RandomDurability.Max"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RandomAmmo.Min"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RandomAmmo.Max"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("AmmoType.TagName"), TEXT("None"));
}
