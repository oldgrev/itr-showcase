#pragma once

#include "CoreMinimal.h"
#include "ERadiusAchievement.h"
#include "ERadiusLeaderboard.h"
#include "IClearable.h"
#include "AchievementsManager.generated.h"

class UAchievementsManager;
class UInventoryItem;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UAchievementsManager : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    UAchievementsManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateLeaderboardProgress(const ERadiusLeaderboard Leaderboard, const int32 Value);

    UFUNCTION(BlueprintCallable, Exec)
    void ResetAchievementProgress();

    UFUNCTION(BlueprintCallable)
    void ReportAchievement(const ERadiusAchievement Achievement, const int32 Value);

private:
    UFUNCTION()
    void OnItemTaken(UInventoryItem* Item);

    UFUNCTION()
    void OnItemBoughtEvent(UInventoryItem* InventoryItem);

public:
    UFUNCTION(BlueprintCallable, Exec)
    void LogCachedAchievements();

    UFUNCTION(BlueprintCallable)
    void Initialize();

    UFUNCTION(BlueprintPure)
    static UAchievementsManager* GetAchievementsManager();

    UFUNCTION(BlueprintCallable)
    void CompleteAchievement(const ERadiusAchievement Achievement);

};
