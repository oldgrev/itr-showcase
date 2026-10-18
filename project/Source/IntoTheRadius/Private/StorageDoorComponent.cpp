#include "StorageDoorComponent.h"
#include "ITRDefaults.h"

UStorageDoorComponent::UStorageDoorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("AngleLimit"), (double)120);
    ITRDefaults::Set(GetClass(), this, TEXT("AngleSnap"), (double)5);
    ITRDefaults::Set(GetClass(), this, TEXT("ControlVectorNormal.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ControlVectorNormal.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ControlVectorNormal.Z"), (double)1);
    ITRDefaults::SetNum(GetClass(), this, TEXT("GameplayTags.GameplayTags"), 0);
    ITRDefaults::SetNum(GetClass(), this, TEXT("GameplayTags.ParentTags"), 0);
}

void UStorageDoorComponent::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const {
}

void UStorageDoorComponent::SetLock(bool lock) {
}

void UStorageDoorComponent::Open() {
}

void UStorageDoorComponent::OnTick() {
}

void UStorageDoorComponent::OnLevelStarted(FGameplayTag LevelTag) {
}

void UStorageDoorComponent::OnGameStarted() {
}

bool UStorageDoorComponent::IsOpened() const {
    return {};
}

bool UStorageDoorComponent::IsClosed() const {
    return {};
}

void UStorageDoorComponent::GetCurrentState(EStorageDoorState& CurrentState) const {
}

void UStorageDoorComponent::Close() {
}

