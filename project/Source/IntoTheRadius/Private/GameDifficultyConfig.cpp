#include "GameDifficultyConfig.h"
#include "ITRDefaults.h"

UGameDifficultyConfig::UGameDifficultyConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.GameDifficultyConfig"));
}

bool UGameDifficultyConfig::IsSleepRestoreHealth() const {
    return {};
}

bool UGameDifficultyConfig::IsShowTips() const {
    return {};
}

bool UGameDifficultyConfig::IsShowLocationOnMap() const {
    return {};
}

bool UGameDifficultyConfig::IsNoEnemies() const {
    return {};
}

bool UGameDifficultyConfig::IsNoAnomalies() const {
    return {};
}

float UGameDifficultyConfig::GetWeaponShotDamageMultiplier() {
    return {};
}

ETracersShowType UGameDifficultyConfig::GetTracersShowType() const {
    return {};
}

float UGameDifficultyConfig::GetTideTimeMultiplier() {
    return {};
}

float UGameDifficultyConfig::GetMissionMoneyRewardMultiplier() {
    return {};
}

float UGameDifficultyConfig::GetItemSellPriceMultiplier() {
    return {};
}

EItemsDropType UGameDifficultyConfig::GetItemsDropType() {
    return {};
}

float UGameDifficultyConfig::GetHungerMultiplier() {
    return {};
}

UGameDifficultyConfig* UGameDifficultyConfig::GetGameDifficultyConfig() {
    return {};
}

FEnemySenseMultiplier UGameDifficultyConfig::GetEnemySense() {
    return {};
}

float UGameDifficultyConfig::GetEnemyHealthMultiplier() {
    return {};
}

float UGameDifficultyConfig::GetEnemyDamageMultiplier() {
    return {};
}

int32 UGameDifficultyConfig::GetEnemyCountModifier() {
    return {};
}

float UGameDifficultyConfig::GetAnomalyDamageMultiplier() {
    return {};
}

int32 UGameDifficultyConfig::GetAnomalyAmountModifier() {
    return {};
}

