#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "AmmoInfo.h"
#include "AttachmentSlotInfo.h"
#include "IAsset.h"
#include "IPreparable.h"
#include "PRAmmoContainerInfo.h"
#include "PRAnomalyInfo.h"
#include "PRItemInfo.h"
#include "PRNPCInfo.h"
#include "UpgradeInfo.h"
#include "WeaponInfo.h"
#include "InfosConfig.generated.h"

class AActor;
class APRAnomaly;
class UDataTable;
class UInfosConfig;
class UObject;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UInfosConfig : public UDataAsset, public IIAsset, public IIPreparable {
    GENERATED_BODY()
public:
    UInfosConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetItemProxyClass(FGameplayTag ItemTypeID, TSubclassOf<UObject> ProxyClass);

    UFUNCTION(BlueprintCallable)
    FGameplayTag ResolveItemTypeID(const FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    bool IsValidNPC(FGameplayTag npcTypeID) const;

    UFUNCTION(BlueprintCallable)
    bool IsValidItemTypeID(const FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    bool IsValidAnomaly(const FGameplayTag anomalyTypeID) const;

    UFUNCTION(BlueprintCallable)
    bool IsAmmoContainer(const FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    FUpgradeInfo GetUpgradeInfo(const FGameplayTag UpgradeID) const;

    UFUNCTION(BlueprintCallable)
    int32 GetTypeSellPrice(const FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    int32 GetTypeLevelRequirement(const FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    int32 GetTypeBuyPrice(const FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    FAttachmentSlotInfo GetSlotInfo(const FGameplayTag TypeID) const;

    UFUNCTION(BlueprintCallable)
    TArray<FGameplayTag> GetNPCsListByCores(TArray<FGameplayTag> coreTags) const;

    UFUNCTION(BlueprintCallable)
    const TMap<FGameplayTag, FPRNPCInfo>& GetNPCInfos() const;

    UFUNCTION(BlueprintCallable)
    FPRNPCInfo GetNPCInfo(FGameplayTag npcTypeID) const;

    UFUNCTION(BlueprintCallable)
    TSubclassOf<AActor> GetNPCClass(FGameplayTag npcTypeID) const;

    UFUNCTION(BlueprintCallable)
    FGameplayTag GetNPCByCore(FGameplayTag coreTag) const;

    UFUNCTION(BlueprintCallable)
    TSubclassOf<UObject> GetItemProxyClass(FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    TSubclassOf<AActor> GetItemClass(FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintPure)
    static UInfosConfig* GetInfosConfig();

    UFUNCTION(BlueprintCallable)
    TArray<FPRAmmoContainerInfo> GetContainersForAmmo(FGameplayTag AmmoTypeID) const;

    UFUNCTION(BlueprintCallable)
    FWeaponInfo GetBasicWeaponInfo(const FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    FPRItemInfo GetBasicItemInfo(FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    FPRAmmoContainerInfo GetBasicAmmoContainerInfo(FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    FGameplayTag GetAnotherItemTypeID(FGameplayTag ItemTypeID, bool prev) const;

    UFUNCTION(BlueprintCallable)
    FPRAnomalyInfo GetAnomalyInfo(const FGameplayTag anomalyTypeID) const;

    UFUNCTION(BlueprintCallable)
    TSubclassOf<APRAnomaly> GetAnomalyClass(FGameplayTag anomalyTypeID) const;

    UFUNCTION(BlueprintCallable)
    FText GetAmmoTypeName(const FGameplayTag TypeID) const;

    UFUNCTION(BlueprintCallable)
    FAmmoInfo GetAmmoInfo(const FGameplayTag ItemTypeID) const;

    UFUNCTION(BlueprintCallable)
    FText GetAmmoCaliberName(const FGameplayTag CaliberID) const;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* ItemInfosTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* AmmoContainerInfosTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* AmmoInfosTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* WeaponInfosTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* UpgradeInfosTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* NPCInfosTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* AnomalyInfosTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* AttachmentSlotInfosTable;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FText> AdditionalNames;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FText> AmmoCaliberNames;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FText> AmmoTypeNames;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FGameplayTag> ExcludeFromSave;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FGameplayTag, FGameplayTag> ReplaceItemTagsFromSave;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxWeaponDamage;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxWeaponShootingStability;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxWeaponRecoilForce;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxWeaponAccuracy;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxWeaponFireRate;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxDurability;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float MaxReliability;
};
