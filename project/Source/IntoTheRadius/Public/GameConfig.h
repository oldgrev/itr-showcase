#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "CloseCombatManagerConfig.h"
#include "ConditionsList.h"
#include "IAsset.h"
#include "MinMaxFloat.h"
#include "NPCAwarenessValues.h"
#include "PRLootTableConfig.h"
#include "PRTriggerConfig.h"
#include "ShopShowcaseSideConfig.h"
#include "StartupConfig.h"
#include "TideTriggerConfig.h"
#include "TutorialConfig.h"
#include "GameConfig.generated.h"

class UGameConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UGameConfig : public UDataAsset, public IIAsset {
    GENERATED_BODY()
public:
    UGameConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static UGameConfig* GetGameConfig();

    UFUNCTION(BlueprintCallable)
    void ApplyStartupConfig(FStartupConfig Config);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float LootSpawnDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool DisableInputInTransitionMonologue;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool SkipTransitionMonologueInProd;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FText> LoadingHints;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float LoadingHintsChangeTime;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float LoadingHintsPSOUpdateTime;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MissionAbortCooldownSeconds;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName BulletsTag;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FDateTime ReleaseDateTime;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FPRTriggerConfig> GeneralTriggers;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FTideTriggerConfig> TideTriggers;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> EAPrizes;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float RealMinutesInGameHour;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, float> RealMinutesInGameHourOverride;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float TidePeriodInGameHours;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float TideSignalInGameSeconds;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> ItemTypesToDestroyOnTide;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float FogReEnterGameHoursSkip;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<int32, FConditionsList> SpecialClustersCounts;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool OnlyBigClustersAreSpecial;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag SpecialClusterArtifactTypeID;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<int32, FConditionsList> SpecialGeneratorsCounts;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag SpecialGeneratorShardTypeID;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag OrdinaryGeneratorShardTypeID;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> BannedFromBeingSpecial;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float AutosaveTimeRealSeconds;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool AutosaveOnIronmanDeath;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float AutosaveIconShownSeconds;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool UseSaveMessageIcon;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FTutorialConfig> TutorialConfigs;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 MinimumPlayerLevelToSkipTutorials;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FDateTime StartGameDate;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FStartupConfig StartupConfig;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FNPCAwarenessValues NPCAwarenessValues;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float ActivationDistanceToPlayer;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float CriticalDamageMultiplier;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FCloseCombatManagerConfig CloseCombatConfig;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float AnomalySpawnMultiplier;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float AnomalySpawnBlockCutoffRadiusMultiplier;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float AnomaliesSpawnDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FPRLootTableConfig> LootArray;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 SellPricePercent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FShopShowcaseSideConfig> ShowcaseSides;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FLinearColor ShopSlotInfoTextColor;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 RepairPriceToItemPrice;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float RepairSeconds;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTagContainer NonRepairableItems;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FGameplayTagContainer> WeaponUnlockMission;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FName, FMinMaxFloat> ItemDurabilityPercents;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTagContainer RodableItems;
};
