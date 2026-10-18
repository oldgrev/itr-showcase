#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EPRHandPoseType.h"
#include "PRItemInfo.h"
#include "IPRItem.generated.h"

class UHolsterComponent;
class UInventoryItem;

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIPRItem : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIPRItem {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UpdateSkin();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool UpdateInventoryItemLocation();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UpdateFireMode();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void UpdateAttachmentSlots();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void StopUse();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetupProxySystem(const bool bStartWithProxy, const bool bStartVisible);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetProxyMode(const bool bUseProxy);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SetItemVisibility(const bool bNewVisibility);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetDistanceGripEnable(bool enable);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void RegisterMeshComponentsAndOmittableColliders();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void Reconfigure(UInventoryItem* InventoryItem, bool& success);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnRemovedFromHolster(UHolsterComponent* Holster);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnProxySystemReady();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnProxyEnabled();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnProxyDisabled();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnAddedToHolster(UHolsterComponent* Holster);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsItemInDelivery() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void InitBought();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FGameplayTag GetTypeID() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetProxyMode(bool& bUseProxy) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    UInventoryItem* GetPreparedItem() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FTransform GetPoseShift(EPRHandPoseType PoseType) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetItemVisibility(bool& bIsVisible) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FPRItemInfo GetItemInfo() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void GetItemCenterTransform(bool& socket, FTransform& itemCenterTransform);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    UInventoryItem* GetInventoryItem() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    EPRHandPoseType GetDefaultPoseType() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetCurrentWeight() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetCurrentCondition() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetConditionPercent() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FGameplayTag GetAttachmentTypeID() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetAttachmentsList(TArray<FString>& Attachments);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FString GetActorUID() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool DropItemOnGround();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void DisableItemPhysics();

};
