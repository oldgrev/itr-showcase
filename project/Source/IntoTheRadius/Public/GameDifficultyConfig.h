#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EDifficultyType.h"
#include "EItemsDropType.h"
#include "EPRGameDifficultyPreset.h"
#include "ETracersShowType.h"
#include "EnemySenseMultiplier.h"
#include "IAsset.h"
#include "RadiusGameDifficulty.h"
#include "GameDifficultyConfig.generated.h"

class UGameDifficultyConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UGameDifficultyConfig : public UDataAsset, public IIAsset {
    GENERATED_BODY()
public:
    UGameDifficultyConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool IsSleepRestoreHealth() const;

    UFUNCTION(BlueprintCallable)
    bool IsShowTips() const;

    UFUNCTION(BlueprintCallable)
    bool IsShowLocationOnMap() const;

    UFUNCTION(BlueprintCallable)
    bool IsNoEnemies() const;

    UFUNCTION(BlueprintCallable)
    bool IsNoAnomalies() const;

    UFUNCTION(BlueprintPure)
    float GetWeaponShotDamageMultiplier();

    UFUNCTION(BlueprintCallable)
    ETracersShowType GetTracersShowType() const;

    UFUNCTION(BlueprintPure)
    float GetTideTimeMultiplier();

    UFUNCTION(BlueprintPure)
    float GetMissionMoneyRewardMultiplier();

    UFUNCTION(BlueprintPure)
    float GetItemSellPriceMultiplier();

    UFUNCTION(BlueprintPure)
    EItemsDropType GetItemsDropType();

    UFUNCTION(BlueprintPure)
    float GetHungerMultiplier();

    UFUNCTION(BlueprintPure)
    static UGameDifficultyConfig* GetGameDifficultyConfig();

    UFUNCTION(BlueprintPure)
    FEnemySenseMultiplier GetEnemySense();

    UFUNCTION(BlueprintPure)
    float GetEnemyHealthMultiplier();

    UFUNCTION(BlueprintPure)
    float GetEnemyDamageMultiplier();

    UFUNCTION(BlueprintPure)
    int32 GetEnemyCountModifier();

    UFUNCTION(BlueprintPure)
    float GetAnomalyDamageMultiplier();

    UFUNCTION(BlueprintPure)
    int32 GetAnomalyAmountModifier();

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EPRGameDifficultyPreset, FRadiusGameDifficulty> Presets;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EPRGameDifficultyPreset, FText> DifficultyPresetTypeNames;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, FText> DifficultyTypeNames;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EItemsDropType, FText> ItemsDropTypeNames;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<ETracersShowType, FText> TracersShowTypeNames;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, FEnemySenseMultiplier> EnemySense;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, float> EnemyHealth;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, float> EnemyDamage;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, int32> EnemyCount;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, float> ItemSellPrice;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, float> WeaponShotDamage;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, float> AnomalyDamage;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, int32> AnomalyAmount;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, float> MissionMoneyReward;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, float> Hunger;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<EDifficultyType, float> TideTime;
};
