#include "CloseCombatManager.h"

UCloseCombatManager::UCloseCombatManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UCloseCombatManager::UnregisterNpc(ACharacter* NpcToUnregister) {
}

void UCloseCombatManager::ToggleDebug() {
}

void UCloseCombatManager::RegisterNpc(ACharacter* NpcToRegister) {
}

void UCloseCombatManager::InitData() {
}

float UCloseCombatManager::GetTeleportSearchRadius() const {
    return {};
}

float UCloseCombatManager::GetMinDistanceFromPlayerToReappear() const {
    return {};
}

bool UCloseCombatManager::GetDebugEnabled() const {
    return {};
}

ENpcCombatState UCloseCombatManager::GetCloseCombatState(ACharacter* NPC) const {
    return {};
}

UCloseCombatManager* UCloseCombatManager::GetCloseCombatManager() {
    return {};
}

void UCloseCombatManager::DebugSetBudget(const float NewBudget) {
}

void UCloseCombatManager::DebugGetBudget(float& CCBudget, float& Weight) {
}

void UCloseCombatManager::CleanData() {
}

