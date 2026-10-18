#include "PlayerStatsComponent.h"

UPlayerStatsComponent::UPlayerStatsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UPlayerStatsComponent::SetStats(const int32 HealthPercent, const int32 StaminaPercent, const int32 RestPercent, const int32 NutritionPercent, const int32 HungerPercent) {
}

void UPlayerStatsComponent::SetStamina(const float Value) {
}

void UPlayerStatsComponent::SetHealth(float Health) {
}

void UPlayerStatsComponent::Reset(bool bAlive) {
}

void UPlayerStatsComponent::RegenerateHealth(float DeltaSeconds) {
}

bool UPlayerStatsComponent::HasStamina() {
    return {};
}

bool UPlayerStatsComponent::HasRest() {
    return {};
}

bool UPlayerStatsComponent::HasNutrition() {
    return {};
}

void UPlayerStatsComponent::GetStatus(EPRStatStatus& Health, EPRStatStatus& Stamina, EPRStatStatus& Nutrition) {
}

void UPlayerStatsComponent::GetStats(float& Health, float& HealthPercent, float& Stamina, float& StaminaPercent, float& Rest, float& RestPercent, float& Nutrition, float& NutritionPercent) {
}

void UPlayerStatsComponent::GetStaminaPercent(float& StaminaPercent) {
}

void UPlayerStatsComponent::GetSleepTimeTillRested(const int32 RestPercent, float& Seconds) {
}

void UPlayerStatsComponent::GetSleepTimeTillHealed(const int32 HealthPercent, float& Seconds) {
}

void UPlayerStatsComponent::GetRestPercent(float& RestPercent) {
}

void UPlayerStatsComponent::GetMaxAvailableStamina(float& Stamina, float& MaxAvailable) {
}

void UPlayerStatsComponent::GetHealthMax(float& HealthMax) {
}

bool UPlayerStatsComponent::EnoughStamina(const float Stamina) {
    return {};
}

void UPlayerStatsComponent::ChangeStamina(const float Delta) {
}

void UPlayerStatsComponent::ChangeRestByPercent(const int32 Percent) {
}

void UPlayerStatsComponent::ChangeRest(const float Delta, const bool bBuff) {
}

void UPlayerStatsComponent::ChangeNutrition(const float Delta) {
}

void UPlayerStatsComponent::ChangeHealthByPercent(int32 Percent) {
}

bool UPlayerStatsComponent::CanRegenerateHealth() {
    return {};
}

void UPlayerStatsComponent::AllowRegeneration(float HealthRegenStart, float HealthRegenMax, float HealthRegenPerSecond) {
}

