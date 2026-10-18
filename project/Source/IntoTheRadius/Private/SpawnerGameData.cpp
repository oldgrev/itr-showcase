#include "SpawnerGameData.h"
#include "ITRDefaults.h"

USpawnerGameData::USpawnerGameData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("spawnSeed"), (double)1628871468);
}

FString USpawnerGameData::ToString() const {
    return {};
}

void USpawnerGameData::SpawnSavedItems(const FString SpawnerId) {
}

void USpawnerGameData::SpawnSavedArtifacts(const FString SpawnerId) {
}

void USpawnerGameData::SpawnSavedAnomalies(const FString SpawnerId) {
}

void USpawnerGameData::SpawnLootSpawnerData(const FString InstanceId, bool& HasData, bool& NeedPlacement, TArray<UInventoryItem*>& spawned) {
}

void USpawnerGameData::SaveSpawnedLootData(const FString InstanceId, const TArray<UInventoryItem*> Loot) {
}

void USpawnerGameData::SaveSpawnedItemData(const FString SpawnerId, UInventoryItem* Item, const FTransform Transform) {
}

void USpawnerGameData::SaveSpawnedArtifactData(const FString SpawnerId, const FString InstanceId, const FGameplayTag TypeID, const FTransform Transform) {
}

void USpawnerGameData::SaveSpawnedAnomalyData(const FString SpawnerId, APRAnomaly* anomaly) {
}

void USpawnerGameData::SaveNpcData(const FString SpawnerId, const FNPCGameData Data) {
}

void USpawnerGameData::SaveGeneratorData(const FString generatorID, const float HP, const FTransform Transform, const float Cooldown) {
}

void USpawnerGameData::SaveGeneratedLootData(const FString InstanceId, const TArray<UInventoryItem*> Loot) {
}

void USpawnerGameData::SaveFurnitureSocketData(const FString InstanceId, const TMap<FName, FTransform>& Data, const TArray<FName>& Broken) {
}

void USpawnerGameData::SaveFurnitureEmptySocket(const FString InstanceId, const FName& EmptySlotId) {
}

void USpawnerGameData::SaveEmptyLootData(const FString InstanceId) {
}

void USpawnerGameData::SaveBodyType(const FString SpawnerId, const int32 BodyType) {
}

void USpawnerGameData::SaveAnomalyData(const FString SpawnerId, const FAnomalyData Data) {
}

void USpawnerGameData::RemoveSpawnedItemData(UInventoryItem* Item) {
}

void USpawnerGameData::RemoveNpcData(const FString SpawnerId, const FString InstanceId) {
}

void USpawnerGameData::RemoveFieldDataArtifact(const FString InstanceId) {
}

FSpawnSlotData USpawnerGameData::MakeFurnitureSlotData(TArray<UInventoryItem*> Items) {
    return {};
}

bool USpawnerGameData::IsGeneratorSaved(const FString generatorID) const {
    return {};
}

bool USpawnerGameData::HasSpawner(const FString SpawnerId) const {
    return {};
}

void USpawnerGameData::HasLootSpawnerData(const FString InstanceId, bool& bHasData) const {
}

FRandomStream USpawnerGameData::GetRandomStream(const FString SpawnerId) const {
    return {};
}

void USpawnerGameData::GetNpcData(const FString SpawnerId, TMap<FString, FNPCGameData>& DataMap) {
}

void USpawnerGameData::GetLootSpawnerData(const FString InstanceId, TArray<UInventoryItem*>& Loot, bool& bIsEmpty, bool& bHasData) {
}

void USpawnerGameData::GetFurnitureData(const FString InstanceId, FFurnitureData& Data, FNameArray& BrokenSlots, FNameArray& EmptySlots, bool& bHasData) {
}

int32 USpawnerGameData::GetBodyType(const FString SpawnerId) {
    return {};
}

void USpawnerGameData::GetAnomalyFieldData(const FString SpawnerId, FAnomalyFieldData& Data) {
}

FAnomalyData USpawnerGameData::GetAnomalyData(const FString SpawnerId) {
    return {};
}

