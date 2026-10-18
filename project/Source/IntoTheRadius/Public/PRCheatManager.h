#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "GameplayTagContainer.h"
#include "PRCheatManager.generated.h"

class UInventoryItem;
class UMissionData;

UCLASS(Blueprintable, BlueprintType, Within=PlayerController)
class INTOTHERADIUS_API UPRCheatManager : public UCheatManager {
    GENERATED_BODY()
public:
    UPRCheatManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(Exec)
    static void UnlockAllWeapons();

    UFUNCTION(BlueprintCallable, Exec)
    void ToggleProjectileDraw();

    UFUNCTION(Exec)
    void SpawnItem(const FString Tag);

    UFUNCTION(Exec)
    static void ShowRevision();

    UFUNCTION(BlueprintCallable)
    void SetSkipTutorial(bool b_new_skip);

    UFUNCTION(Exec)
    static void SecurityLevel(const int32 Level);

    UFUNCTION(Exec)
    void RIP() const;

    UFUNCTION(BlueprintCallable)
    void ResetTideTimer() const;

    UFUNCTION(BlueprintCallable)
    void RefillAmmoContainer(UInventoryItem* Item) const;

    UFUNCTION(Exec)
    void RefillAmmo() const;

    UFUNCTION(BlueprintCallable)
    void RaiseCrashReport();

    UFUNCTION(Exec)
    void PrintActors();

    UFUNCTION(BlueprintCallable)
    bool IsProjectileDraw() const;

    UFUNCTION(Exec)
    void GiveMeTheWeapon(const FString Tag);

    UFUNCTION(Exec)
    static void GiveMeTheMoney(const int32 Amount);

    UFUNCTION(Exec)
    static void GiveMeTheDurability(const int32 Value);

    UFUNCTION(Exec)
    void GiveMeTheBullets();

    UFUNCTION(BlueprintCallable)
    bool GetSkipTutorial() const;

    UFUNCTION(BlueprintCallable)
    void GetMission(const FGameplayTag MissionInstanceId, UMissionData*& MissionData) const;

    UFUNCTION(BlueprintPure)
    TArray<FGameplayTag> GetChildTags(const FGameplayTag parentTag);

    UFUNCTION(BlueprintCallable)
    UInventoryItem* DoSpawnItem(const FGameplayTag Tag);

    UFUNCTION(Exec)
    void ChangeHealth(const int32 Delta) const;

    UFUNCTION(BlueprintCallable)
    void AddMission(UMissionData* MissionData);

};
