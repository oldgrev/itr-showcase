#include "InfosConfig.h"
#include "ITRDefaults.h"

UInfosConfig::UInfosConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.InfosConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("MaxWeaponDamage"), (double)250);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxWeaponShootingStability"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxWeaponRecoilForce"), (double)200);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxWeaponAccuracy"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxWeaponFireRate"), (double)1500);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxDurability"), (double)100);
    ITRDefaults::Set(GetClass(), this, TEXT("MaxReliability"), (double)3);
}

void UInfosConfig::SetItemProxyClass(FGameplayTag ItemTypeID, TSubclassOf<UObject> ProxyClass) {
}

FGameplayTag UInfosConfig::ResolveItemTypeID(const FGameplayTag ItemTypeID) const {
    return {};
}

bool UInfosConfig::IsValidNPC(FGameplayTag npcTypeID) const {
    return {};
}

bool UInfosConfig::IsValidItemTypeID(const FGameplayTag ItemTypeID) const {
    return {};
}

bool UInfosConfig::IsValidAnomaly(const FGameplayTag anomalyTypeID) const {
    return {};
}

bool UInfosConfig::IsAmmoContainer(const FGameplayTag ItemTypeID) const {
    return {};
}

FUpgradeInfo UInfosConfig::GetUpgradeInfo(const FGameplayTag UpgradeID) const {
    return {};
}

int32 UInfosConfig::GetTypeSellPrice(const FGameplayTag ItemTypeID) const {
    return {};
}

int32 UInfosConfig::GetTypeLevelRequirement(const FGameplayTag ItemTypeID) const {
    return {};
}

int32 UInfosConfig::GetTypeBuyPrice(const FGameplayTag ItemTypeID) const {
    return {};
}

FAttachmentSlotInfo UInfosConfig::GetSlotInfo(const FGameplayTag TypeID) const {
    return {};
}

TArray<FGameplayTag> UInfosConfig::GetNPCsListByCores(TArray<FGameplayTag> coreTags) const {
    return {};
}

const TMap<FGameplayTag, FPRNPCInfo>& UInfosConfig::GetNPCInfos() const {
    static TMap<FGameplayTag, FPRNPCInfo> Dummy;
    return Dummy;
}

FPRNPCInfo UInfosConfig::GetNPCInfo(FGameplayTag npcTypeID) const {
    return {};
}

TSubclassOf<AActor> UInfosConfig::GetNPCClass(FGameplayTag npcTypeID) const {
    return {};
}

FGameplayTag UInfosConfig::GetNPCByCore(FGameplayTag coreTag) const {
    return {};
}

TSubclassOf<UObject> UInfosConfig::GetItemProxyClass(FGameplayTag ItemTypeID) const {
    return {};
}

TSubclassOf<AActor> UInfosConfig::GetItemClass(FGameplayTag ItemTypeID) const {
    return {};
}

UInfosConfig* UInfosConfig::GetInfosConfig() {
    return {};
}

TArray<FPRAmmoContainerInfo> UInfosConfig::GetContainersForAmmo(FGameplayTag AmmoTypeID) const {
    return {};
}

FWeaponInfo UInfosConfig::GetBasicWeaponInfo(const FGameplayTag ItemTypeID) const {
    return {};
}

FPRItemInfo UInfosConfig::GetBasicItemInfo(FGameplayTag ItemTypeID) const {
    return {};
}

FPRAmmoContainerInfo UInfosConfig::GetBasicAmmoContainerInfo(FGameplayTag ItemTypeID) const {
    return {};
}

FGameplayTag UInfosConfig::GetAnotherItemTypeID(FGameplayTag ItemTypeID, bool prev) const {
    return {};
}

FPRAnomalyInfo UInfosConfig::GetAnomalyInfo(const FGameplayTag anomalyTypeID) const {
    return {};
}

TSubclassOf<APRAnomaly> UInfosConfig::GetAnomalyClass(FGameplayTag anomalyTypeID) const {
    return {};
}

FText UInfosConfig::GetAmmoTypeName(const FGameplayTag TypeID) const {
    return {};
}

FAmmoInfo UInfosConfig::GetAmmoInfo(const FGameplayTag ItemTypeID) const {
    return {};
}

FText UInfosConfig::GetAmmoCaliberName(const FGameplayTag CaliberID) const {
    return {};
}

