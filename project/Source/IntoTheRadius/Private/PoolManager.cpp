#include "PoolManager.h"

UPoolManager::UPoolManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UPoolManager::ReturnActor(AActor* Actor) {
    return {};
}

void UPoolManager::PrefillPoolFromConfig() {
}

bool UPoolManager::IsActorInPool(const AActor* Actor) {
    return {};
}

UPoolManager* UPoolManager::GetPoolManager() {
    return {};
}

AActor* UPoolManager::GetActor(const TSubclassOf<AActor> ActorClass, const FTransform Transform, AActor* Owner, APawn* Instigator) {
    return {};
}

