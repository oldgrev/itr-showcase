#include "WeaponBoltComponent.h"
#include "ITRDefaults.h"

UWeaponBoltComponent::UWeaponBoltComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("AngleLimit"), (double)-90);
    ITRDefaults::Set(GetClass(), this, TEXT("AutoCloseRotateOnRelease"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("SnapPercent"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("SlideLimit"), (double)-10);
    ITRDefaults::Set(GetClass(), this, TEXT("StickToOpen"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("RotationCoeff"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("SlideCoeff"), (double)2);
    ITRDefaults::SetNum(GetClass(), this, TEXT("GameplayTags.GameplayTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("GameplayTags.ParentTags"), 0);
}

void UWeaponBoltComponent::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const {
}

void UWeaponBoltComponent::OnTick() {
}

void UWeaponBoltComponent::OnLevelStarted(FGameplayTag LevelTag) {
}

void UWeaponBoltComponent::OnGameStarted() {
}

bool UWeaponBoltComponent::IsOpened() const {
    return {};
}

bool UWeaponBoltComponent::IsClosed() const {
    return {};
}

void UWeaponBoltComponent::GetCurrentState(EWeaponBoltState& CurrentState) const {
}

void UWeaponBoltComponent::Drop() {
}

