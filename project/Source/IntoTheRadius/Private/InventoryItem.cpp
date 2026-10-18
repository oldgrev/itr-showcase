#include "InventoryItem.h"
#include "ITRDefaults.h"

UInventoryItem::UInventoryItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.InventoryItem"));
    ITRDefaults::Set(GetClass(), this, TEXT("ItemId.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("HolderID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("HolderRelativeTransform.Rotation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderRelativeTransform.Rotation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderRelativeTransform.Rotation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderRelativeTransform.Rotation.W"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderRelativeTransform.Translation.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderRelativeTransform.Translation.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderRelativeTransform.Translation.Z"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderRelativeTransform.Scale3D.X"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderRelativeTransform.Scale3D.Y"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("HolderRelativeTransform.Scale3D.Z"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("AmmoInfo.ChamberAmmo.TagName"), TEXT("None"));
}

bool UInventoryItem::UpdateUpgrades(const TArray<FGameplayTag> UpgradeIDs, const bool bChangeMoney) {
    return {};
}

void UInventoryItem::UpdateDurabilityByUpgrade(const FGameplayTag UpgradeID) {
}

bool UInventoryItem::SwitchFireMode() {
    return {};
}

bool UInventoryItem::SetFireMode(const EWeaponFireMode FireMode) {
    return {};
}

void UInventoryItem::SetDurability(const float Value, bool& bSuccess) {
}

void UInventoryItem::SetChamberAmmo(const FGameplayTag ChamberAmmo) {
}

void UInventoryItem::SetBoltState(const EWeaponBoltState BoltState) {
}

void UInventoryItem::SetAmmo(TArray<FGameplayTag> Ammo) {
}

bool UInventoryItem::RemoveUpgrade(const FGameplayTag UpgradeID) {
    return {};
}

void UInventoryItem::RemoveExactAmmo(int32 Index, bool& bSuccess, FGameplayTag& Ammo) {
}

void UInventoryItem::RemoveAmmo(bool& bSuccess, FGameplayTag& Ammo) {
}

void UInventoryItem::PrintItem(const FString& Message) {
}

bool UInventoryItem::IsUpgradeAvailable(const FGameplayTag UpgradeID, const bool bMoneyCheck) {
    return {};
}

bool UInventoryItem::IsRepairable() {
    return {};
}

bool UInventoryItem::IsArmorItem() {
    return {};
}

bool UInventoryItem::IsAmmoTypeAcceptable(FGameplayTag AmmoTag) {
    return {};
}

void UInventoryItem::IsActorOfAcceptableAmmo(AActor* AmmoActor, bool& bAcceptable, FGameplayTag& AmmoTag) {
}

bool UInventoryItem::InstallUpgrade(const FGameplayTag UpgradeID, const bool bChangeMoney) {
    return {};
}

bool UInventoryItem::HasFireMode(const EWeaponFireMode FireMode) {
    return {};
}

bool UInventoryItem::HasDamageCategoryArmor(EDamageCategory DamageCategory) {
    return {};
}

FWeaponInfo UInventoryItem::GetWeaponInfo() {
    return {};
}

void UInventoryItem::GetSilencerAttachment(UInventoryItem*& AttachItem) {
}

int32 UInventoryItem::GetSellPrice(bool bIgnoreIfAttached, bool bItemOnly) {
    return {};
}

int32 UInventoryItem::GetRepairTime(bool bIgnoreIfAttached) {
    return {};
}

int32 UInventoryItem::GetRepairPrice(bool bIgnoreIfAttached) {
    return {};
}

TArray<FGameplayTag> UInventoryItem::GetPossibleUpgrades() {
    return {};
}

void UInventoryItem::GetNextAmmo(FGameplayTag& NextAmmoTag) {
}

float UInventoryItem::GetMaxDurability() {
    return {};
}

int32 UInventoryItem::GetMaxAmmoCapacity() {
    return {};
}

void UInventoryItem::GetMagAttachment(UInventoryItem*& AttachItem) {
}

float UInventoryItem::GetItemWeight(bool bIgnoreAttachments) {
    return {};
}

FPRItemInfo UInventoryItem::GetItemInfo() {
    return {};
}

EWeaponFireMode UInventoryItem::GetFireMode() const {
    return {};
}

float UInventoryItem::GetDurabilityRatio() {
    return {};
}

float UInventoryItem::GetDamageCategoryArmor(EDamageCategory DamageCategory) {
    return {};
}

EWeaponBoltState UInventoryItem::GetBoltState() const {
    return {};
}

void UInventoryItem::GetAttachments(const FGameplayTag TypeTag, TArray<UInventoryItem*>& AttachItems) {
}

FString UInventoryItem::GetAmmoTypeName() {
    return {};
}

FString UInventoryItem::GetAmmoString() {
    return {};
}

FPRAmmoContainerInfo UInventoryItem::GetAmmoContainerInfo() {
    return {};
}

void UInventoryItem::GetAllAttachments(TArray<UInventoryItem*>& AttachItems) {
}

void UInventoryItem::ChangeDurabilityByRatio(const float Ratio, const EDamageCategory DamageCategory, bool& bSuccess, float& ChangedBy) {
}

void UInventoryItem::ChangeDurability(const float bY, const EDamageCategory DamageCategory, bool& bSuccess, float& ChangedBy) {
}

void UInventoryItem::ChangeAmmoContainerDurability(bool& bSuccess, float& ChangedBy) {
}

void UInventoryItem::ChamberNextAmmo() {
}

void UInventoryItem::AddAmmo(FGameplayTag AmmoTag, bool& bSuccess) {
}

