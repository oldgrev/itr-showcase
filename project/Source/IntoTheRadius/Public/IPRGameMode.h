#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NPCGameData.h"
#include "IPRGameMode.generated.h"

class AActor;
class APRAnomaly;
class APREnvironment;
class UInventoryItem;
class UPRItemConfig;

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIPRGameMode : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIPRGameMode {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool TransferToLevel(const FGameplayTag LevelTag, const FGameplayTag LocationTag);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    AActor* SpawnSavedNPC(const FNPCGameData Data, AActor* SpawnerActor, const float Radius, const bool bCanWalkAway, const bool SnipingMode);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    AActor* SpawnNPC(const FGameplayTag npcTypeID, AActor* SpawnerActor, const float Radius, const bool bCanWalkAway, const bool SnipingMode);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    AActor* SpawnItemConfig(UPRItemConfig* itemConfig, const FTransform Transform, const bool bProjectOnGround, const bool bSimulate, const bool bAddToPlayer);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    AActor* SpawnItemByType(const FGameplayTag& ItemTypeID, const FString& InstanceId, const FTransform& Transform, bool bProjectOnGround, bool bSimulate);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    AActor* SpawnItem(UInventoryItem* InventoryItem, FTransform Transform, bool bProjectOnGround, bool bSimulate);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    APRAnomaly* SpawnAnomaly(const FString& AnomalyName, TSubclassOf<APRAnomaly> AnomalyClass, FTransform AnomalyTransform, bool bProjectOnGround, float AnomalyRadius);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool SleepAllowed() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetSleepAllowed(const bool bAllow);

    UFUNCTION(BlueprintNativeEvent)
    void ResetPlayerAndItems();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    FVector ReprojectLocation(FVector Location);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ReEnterCurrentLevel();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnPlayerDeath();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void LaunchMainMenu();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void LaunchGame(const bool bStart);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    float GetNoiseAwarenessValue(FName Tag) const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    APREnvironment* GetEnvironment();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    float GetDamageAwarenessValue(float Damage) const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    FTransform GetCurrentPlayerTransform() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void FinishTutorial();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void FindSpawnLocation(FVector nearby, float InRadius, bool bReachable, bool& bSuccess, FVector& Location);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ContinueAsFreeGame();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ApplySoundVolumes();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void ApplyBrigtnessMult();

};
