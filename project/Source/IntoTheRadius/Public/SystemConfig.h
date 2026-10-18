#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "AchievementsConfig.h"
#include "EPRControllerType.h"
#include "EPlayerTeleportAdjustType.h"
#include "GameplayTagsTuple.h"
#include "GraphicsPresetSettings.h"
#include "IAsset.h"
#include "LevelConfig.h"
#include "PRClusterPatternConfig.h"
#include "SystemConfig.generated.h"

class AActor;
class APRClusterPattern;
class UDamageType;
class UMaterialInterface;
class UStaticMesh;
class USystemConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API USystemConfig : public UDataAsset, public IIAsset {
    GENERATED_BODY()
public:
    USystemConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool IsTutorialLevel(const FGameplayTag& LevelTag) const;

    UFUNCTION(BlueprintCallable)
    bool IsLevelTagValid(FGameplayTag LevelTag) const;

    UFUNCTION(BlueprintPure)
    static USystemConfig* GetSystemConfig();

    UFUNCTION(BlueprintCallable)
    FText GetLevelName(const FGameplayTag& LevelTag, const FText& Placeholder) const;

    UFUNCTION(BlueprintCallable)
    void GetLevelConfig(FGameplayTag LevelTag, FLevelConfig& Config) const;

    UFUNCTION(BlueprintCallable)
    void GetCurrentLevelConfig(FLevelConfig& Config) const;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FLevelConfig> LevelConfigurations;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UMaterialInterface* EmptyMapMaterial;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName CommonLevelName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName TransitionSublevelName;
    UPROPERTY(BlueprintReadOnly)
    float FogFadeTime;
    UPROPERTY(BlueprintReadOnly)
    float FogFadeDensityMultiplier;
    UPROPERTY(BlueprintReadOnly)
    float TransitionTimeSkipHoursPerSecond;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool DisableFirstLaunchInEditor;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector LevelItemsSpawnBlockExtent;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector CorpseSpawnBlockExtent;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float DetectorWorkDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float AmmoContainersLockDelay;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float AmmoContainersLoadingDelay;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<TSubclassOf<APRClusterPattern>, FPRClusterPatternConfig> ClusterPatternConfigs;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<TSubclassOf<UDamageType>> ItemIgnoredDamageTypes;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool LoadShortNPCGameData;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float IngameMenuVerticalShift;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float FallThroughFloorZ;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool DoNotDropItemsFromBackpack;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> ItemsToAdditionalDropOnDeath;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float BulletsFlyBySoundDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float NPCDiscoverDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float AnomalyDiscoverDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<UStaticMesh*> CorpseMeshes;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FString> LowLevelGPUs;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FString> HighLevelGPUs;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<TSubclassOf<AActor>> OnStartSpawningControllers;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EPlayerTeleportAdjustType PlayerPositionAdjustmentInMenu;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EPlayerTeleportAdjustType PlayerPositionAdjustmentInTransition;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool MainMenuFollowsPlayer;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool bCountEditorAsEarlyAccess;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool AwaitForDetectionOnStartup;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FString, EPRControllerType> SteamControllerTypesMap;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool ExitIfUnsupportedControllers;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FString SteamBetaBranchName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FString> SteamHideRevisionBranches;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float ClustersSpawnDistance;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool ClearProfileSavesOnFinalSuicide;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float LevelTransferStepsDelay;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTagsTuple> ItemMoveHoldersMapping;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float NPCSpawnMinDistanceFromPlayer;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float NPCSpawnZShift;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float NPCMaxDistanceFromSpawner;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float NPCSpawnerRestoreRadius;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FAchievementsConfig AchievementsConfig;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGraphicsPresetSettings GraphicsPresetLow;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGraphicsPresetSettings GraphicsPresetMedium;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGraphicsPresetSettings GraphicsPresetHigh;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGraphicsPresetSettings GraphicsPresetUltra;
};
