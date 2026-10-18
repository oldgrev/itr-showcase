#include "AchievementsManager.h"

UAchievementsManager::UAchievementsManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UAchievementsManager::UpdateLeaderboardProgress(const ERadiusLeaderboard Leaderboard, const int32 Value) {
}

void UAchievementsManager::ResetAchievementProgress() {
}

void UAchievementsManager::ReportAchievement(const ERadiusAchievement Achievement, const int32 Value) {
}

void UAchievementsManager::OnItemTaken(UInventoryItem* Item) {
}

void UAchievementsManager::OnItemBoughtEvent(UInventoryItem* InventoryItem) {
}

void UAchievementsManager::LogCachedAchievements() {
}

void UAchievementsManager::Initialize() {
}

UAchievementsManager* UAchievementsManager::GetAchievementsManager() {
    return {};
}

void UAchievementsManager::CompleteAchievement(const ERadiusAchievement Achievement) {
}

