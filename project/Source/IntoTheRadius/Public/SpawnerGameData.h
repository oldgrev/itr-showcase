#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AnomalyData.h"
#include "AnomalyFieldData.h"
#include "FurnitureData.h"
#include "IClearable.h"
#include "NPCDataMap.h"
#include "NPCGameData.h"
#include "NameArray.h"
#include "SpawnSlotData.h"
#include "SpawnerGameData.generated.h"

class APRAnomaly;
class UInventoryItem;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API USpawnerGameData : public UObject, public IIClearable {
    GENERATED_BODY()
public:
    USpawnerGameData(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FString ToString() const;

    UFUNCTION(BlueprintCallable)
    void SpawnSavedItems(const FString SpawnerId);

    UFUNCTION(BlueprintCallable)
    void SpawnSavedArtifacts(const FString SpawnerId);

    UFUNCTION(BlueprintCallable)
    void SpawnSavedAnomalies(const FString SpawnerId);

    UFUNCTION(BlueprintCallable)
    void SpawnLootSpawnerData(const FString InstanceId, bool& HasData, bool& NeedPlacement, TArray<UInventoryItem*>& spawned);

    UFUNCTION(BlueprintCallable)
    void SaveSpawnedLootData(const FString InstanceId, const TArray<UInventoryItem*> Loot);

    UFUNCTION(BlueprintCallable)
    void SaveSpawnedItemData(const FString SpawnerId, UInventoryItem* Item, const FTransform Transform);

    UFUNCTION(BlueprintCallable)
    void SaveSpawnedArtifactData(const FString SpawnerId, const FString InstanceId, const FGameplayTag TypeID, const FTransform Transform);

    UFUNCTION(BlueprintCallable)
    void SaveSpawnedAnomalyData(const FString SpawnerId, APRAnomaly* anomaly);

    UFUNCTION(BlueprintCallable)
    void SaveNpcData(const FString SpawnerId, const FNPCGameData Data);

    UFUNCTION(BlueprintCallable)
    void SaveGeneratorData(const FString generatorID, const float HP, const FTransform Transform, const float Cooldown);

    UFUNCTION(BlueprintCallable)
    void SaveGeneratedLootData(const FString InstanceId, const TArray<UInventoryItem*> Loot);

    UFUNCTION(BlueprintCallable)
    void SaveFurnitureSocketData(const FString InstanceId, const TMap<FName, FTransform>& Data, const TArray<FName>& Broken);

    UFUNCTION(BlueprintCallable)
    void SaveFurnitureEmptySocket(const FString InstanceId, const FName& EmptySlotId);

    UFUNCTION(BlueprintCallable)
    void SaveEmptyLootData(const FString InstanceId);

    UFUNCTION(BlueprintCallable)
    void SaveBodyType(const FString SpawnerId, const int32 BodyType);

    UFUNCTION(BlueprintCallable)
    void SaveAnomalyData(const FString SpawnerId, const FAnomalyData Data);

    UFUNCTION(BlueprintCallable)
    void RemoveSpawnedItemData(UInventoryItem* Item);

    UFUNCTION(BlueprintCallable)
    void RemoveNpcData(const FString SpawnerId, const FString InstanceId);

    UFUNCTION(BlueprintCallable)
    void RemoveFieldDataArtifact(const FString InstanceId);

    UFUNCTION(BlueprintPure)
    static FSpawnSlotData MakeFurnitureSlotData(TArray<UInventoryItem*> Items);

    UFUNCTION(BlueprintCallable)
    bool IsGeneratorSaved(const FString generatorID) const;

    UFUNCTION(BlueprintCallable)
    bool HasSpawner(const FString SpawnerId) const;

    UFUNCTION(BlueprintCallable)
    void HasLootSpawnerData(const FString InstanceId, bool& bHasData) const;

    UFUNCTION(BlueprintCallable)
    FRandomStream GetRandomStream(const FString SpawnerId) const;

    UFUNCTION(BlueprintCallable)
    void GetNpcData(const FString SpawnerId, TMap<FString, FNPCGameData>& DataMap);

    UFUNCTION(BlueprintCallable)
    void GetLootSpawnerData(const FString InstanceId, TArray<UInventoryItem*>& Loot, bool& bIsEmpty, bool& bHasData);

    UFUNCTION(BlueprintCallable)
    void GetFurnitureData(const FString InstanceId, FFurnitureData& Data, FNameArray& BrokenSlots, FNameArray& EmptySlots, bool& bHasData);

    UFUNCTION(BlueprintCallable)
    int32 GetBodyType(const FString SpawnerId);

    UFUNCTION(BlueprintCallable)
    void GetAnomalyFieldData(const FString SpawnerId, FAnomalyFieldData& Data);

    UFUNCTION(BlueprintCallable)
    FAnomalyData GetAnomalyData(const FString SpawnerId);

    UPROPERTY(BlueprintReadOnly)
    TMap<FString, FNPCDataMap> npcSpawners;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, FAnomalyFieldData> anomalySpawners;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, FAnomalyData> anomalies;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, int32> SavedCorpseTypes;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, FFurnitureData> FurnitureLootData;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, FNameArray> FurnitureBrokenData;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, FNameArray> FurnitureEmptySlots;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, FSpawnSlotData> LootSpawnerData;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, FNameArray> LootTableExludes;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, int32> LootTablePoints;
    UPROPERTY(BlueprintReadOnly)
    int64 spawnSeed;
    UPROPERTY(BlueprintReadOnly)
    TArray<FString> PickedUpItems;
    UPROPERTY(BlueprintReadOnly)
    TArray<FGameplayTag> SpecialClusters;
    UPROPERTY(BlueprintReadOnly)
    TArray<FGameplayTag> SpecialGenerators;
    UPROPERTY(BlueprintReadOnly)
    TArray<FGameplayTag> ExcludedGenerators;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, float> GeneratorsHP;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, FTransform> GeneratorsTransforms;
    UPROPERTY(BlueprintReadOnly)
    TMap<FString, float> GeneratorsCooldown;
};
