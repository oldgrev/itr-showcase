#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "AmmoContainerData.h"
#include "EDamageCategory.h"
#include "EItemSlot.h"
#include "EWeaponBoltState.h"
#include "EWeaponFireMode.h"
#include "NoParamsDelegate.h"
#include "PRAmmoContainerInfo.h"
#include "PRItemInfo.h"
#include "WeaponInfo.h"
#include "InventoryItem.generated.h"

class AActor;
class UInventoryItem;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UInventoryItem : public UDataAsset {
    GENERATED_BODY()
public:
    UInventoryItem(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool UpdateUpgrades(const TArray<FGameplayTag> UpgradeIDs, const bool bChangeMoney);

    UFUNCTION(BlueprintCallable)
    void UpdateDurabilityByUpgrade(const FGameplayTag UpgradeID);

    UFUNCTION(BlueprintCallable)
    bool SwitchFireMode();

    UFUNCTION(BlueprintCallable)
    bool SetFireMode(const EWeaponFireMode FireMode);

    UFUNCTION(BlueprintCallable)
    void SetDurability(const float Value, bool& bSuccess);

    UFUNCTION(BlueprintCallable)
    void SetChamberAmmo(const FGameplayTag ChamberAmmo);

    UFUNCTION(BlueprintCallable)
    void SetBoltState(const EWeaponBoltState BoltState);

    UFUNCTION(BlueprintCallable)
    void SetAmmo(TArray<FGameplayTag> Ammo);

    UFUNCTION(BlueprintCallable)
    bool RemoveUpgrade(const FGameplayTag UpgradeID);

    UFUNCTION(BlueprintCallable)
    void RemoveExactAmmo(int32 Index, bool& bSuccess, FGameplayTag& Ammo);

    UFUNCTION(BlueprintCallable)
    void RemoveAmmo(bool& bSuccess, FGameplayTag& Ammo);

    UFUNCTION(BlueprintCallable)
    void PrintItem(const FString& Message);

    UFUNCTION(BlueprintPure)
    bool IsUpgradeAvailable(const FGameplayTag UpgradeID, const bool bMoneyCheck);

    UFUNCTION(BlueprintPure)
    bool IsRepairable();

    UFUNCTION(BlueprintPure)
    bool IsArmorItem();

    UFUNCTION(BlueprintCallable)
    bool IsAmmoTypeAcceptable(FGameplayTag AmmoTag);

    UFUNCTION(BlueprintCallable)
    void IsActorOfAcceptableAmmo(AActor* AmmoActor, bool& bAcceptable, FGameplayTag& AmmoTag);

    UFUNCTION(BlueprintCallable)
    bool InstallUpgrade(const FGameplayTag UpgradeID, const bool bChangeMoney);

    UFUNCTION(BlueprintPure)
    bool HasFireMode(const EWeaponFireMode FireMode);

    UFUNCTION(BlueprintPure)
    bool HasDamageCategoryArmor(EDamageCategory DamageCategory);

    UFUNCTION(BlueprintPure)
    FWeaponInfo GetWeaponInfo();

    UFUNCTION(BlueprintPure)
    void GetSilencerAttachment(UInventoryItem*& AttachItem);

    UFUNCTION(BlueprintPure)
    int32 GetSellPrice(bool bIgnoreIfAttached, bool bItemOnly);

    UFUNCTION(BlueprintPure)
    int32 GetRepairTime(bool bIgnoreIfAttached);

    UFUNCTION(BlueprintPure)
    int32 GetRepairPrice(bool bIgnoreIfAttached);

    UFUNCTION(BlueprintPure)
    TArray<FGameplayTag> GetPossibleUpgrades();

    UFUNCTION(BlueprintPure)
    void GetNextAmmo(FGameplayTag& NextAmmoTag);

    UFUNCTION(BlueprintPure)
    float GetMaxDurability();

    UFUNCTION(BlueprintPure)
    int32 GetMaxAmmoCapacity();

    UFUNCTION(BlueprintPure)
    void GetMagAttachment(UInventoryItem*& AttachItem);

    UFUNCTION(BlueprintPure)
    float GetItemWeight(bool bIgnoreAttachments);

    UFUNCTION(BlueprintPure)
    FPRItemInfo GetItemInfo();

    UFUNCTION(BlueprintCallable)
    EWeaponFireMode GetFireMode() const;

    UFUNCTION(BlueprintPure)
    float GetDurabilityRatio();

    UFUNCTION(BlueprintPure)
    float GetDamageCategoryArmor(EDamageCategory DamageCategory);

    UFUNCTION(BlueprintCallable)
    EWeaponBoltState GetBoltState() const;

    UFUNCTION(BlueprintPure)
    void GetAttachments(const FGameplayTag TypeTag, TArray<UInventoryItem*>& AttachItems);

    UFUNCTION(BlueprintPure)
    FString GetAmmoTypeName();

    UFUNCTION(BlueprintPure)
    FString GetAmmoString();

    UFUNCTION(BlueprintPure)
    FPRAmmoContainerInfo GetAmmoContainerInfo();

    UFUNCTION(BlueprintPure)
    void GetAllAttachments(TArray<UInventoryItem*>& AttachItems);

    UFUNCTION(BlueprintCallable)
    void ChangeDurabilityByRatio(const float Ratio, const EDamageCategory DamageCategory, bool& bSuccess, float& ChangedBy);

    UFUNCTION(BlueprintCallable)
    void ChangeDurability(const float bY, const EDamageCategory DamageCategory, bool& bSuccess, float& ChangedBy);

    UFUNCTION(BlueprintCallable)
    void ChangeAmmoContainerDurability(bool& bSuccess, float& ChangedBy);

    UFUNCTION(BlueprintCallable)
    void ChamberNextAmmo();

    UFUNCTION(BlueprintCallable)
    void AddAmmo(FGameplayTag AmmoTag, bool& bSuccess);

    UPROPERTY(BlueprintAssignable)
    FNoParamsDelegate OnChangeDurability;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FString InstanceId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag ItemId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FString AttachedTo;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EItemSlot AttachmentSlot;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag HolderID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform HolderRelativeTransform;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Durability;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FAmmoContainerData AmmoInfo;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FString> Attachments;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* ActorReference;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> AdditionalTags;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> Upgrades;
};
