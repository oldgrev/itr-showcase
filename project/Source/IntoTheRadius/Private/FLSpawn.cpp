#include "FLSpawn.h"

UFLSpawn::UFLSpawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

AActor* UFLSpawn::SpawnNPC(const UObject* WorldContextObject, const FNpcSpawnInfo NpcSpawnInfo) {
    return {};
}

AActor* UFLSpawn::SpawnNiagaraEmitter(const FTransform Transform, const FRadiusNiagaraEmitterInfo& Info) {
    return {};
}

AActor* UFLSpawn::SpawnItemByType(const UObject* WorldContextObject, const FGameplayTag& ItemTypeID, const FString& InstanceId, const FTransform& Transform, bool bProjectOnGround, bool bSimulatePhysics) {
    return {};
}

AActor* UFLSpawn::SpawnItemByTag(const UObject* WorldContextObject, const FGameplayTag Tag, const USceneComponent* ParentComponent, const bool bSnapToParent, const FTransform& Transform, const bool bPreConfigure, const FString& CustomID) {
    return {};
}

AActor* UFLSpawn::SpawnItemByInventoryItem(const UObject* WorldContextObject, UInventoryItem* InventoryItem, const FTransform& Transform, const bool bProjectOnGround, const bool bSimulatePhysics) {
    return {};
}

AActor* UFLSpawn::SpawnItem(const UObject* WorldContextObject, const FItemSpawnInfo ItemSpawnInfo) {
    return {};
}

AActor* UFLSpawn::SpawnInventoryItem(const UObject* WorldContextObject, UInventoryItem* InventoryItem, const USceneComponent* ParentComponent, const bool bKeepRelativeLocation, const bool bSimulatePhysics) {
    return {};
}

AActor* UFLSpawn::SpawnImpactFromHit(const UObject* WorldContextObject, const FHitResult& Hit, const float ParticleScale, const float DecalScale, const float Distance) {
    return {};
}

AActor* UFLSpawn::SpawnImpact(const FTransform Transform, const FRadiusImpactInfo& Info) {
    return {};
}

AActor* UFLSpawn::SpawnEmitter(const FTransform Transform, const FRadiusEmitterInfo& Info) {
    return {};
}

AActor* UFLSpawn::SpawnBulletShell(const TSubclassOf<AActor> ActorClass, FTransform Transform, const FRadiusFirearmShellInfo ShellInfo) {
    return {};
}

AActor* UFLSpawn::SpawnAnomaly(const UObject* WorldContextObject, const FAnomalySpawnInfo AnomalySpawnInfo) {
    return {};
}

AActor* UFLSpawn::SpawnActorWithTransformDeferred(const UObject* WorldContextObject, const TSubclassOf<AActor> ActorClass, const FTransform Transform) {
    return {};
}

AActor* UFLSpawn::SpawnActorWithIdentityTransform(const UObject* WorldContextObject, const TSubclassOf<AActor> ActorClass, const bool bDeferred) {
    return {};
}

