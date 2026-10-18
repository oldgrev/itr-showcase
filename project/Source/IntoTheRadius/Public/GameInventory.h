#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "IClearable.h"
#include "IPreparable.h"
#include "StringToTagsList.h"
#include "GameInventory.generated.h"

class UInventoryItem;
class UInventoryItemsCollection;
class UOpenedStashIDs;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UGameInventory : public UObject, public IIClearable, public IIPreparable {
    GENERATED_BODY()
public:
    UGameInventory(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetAmmoBeltContent(const FString& InstanceId, TArray<FGameplayTag> beltContent);

    UFUNCTION(BlueprintCallable)
    UInventoryItem* GetItem(const FString& InstanceId);

    UFUNCTION(BlueprintCallable)
    void GetAmmoBeltContent(const FString& InstanceId, TArray<FGameplayTag>& beltContent);

    UPROPERTY()
    UInventoryItemsCollection* PlayerInventory;
    UPROPERTY()
    UInventoryItemsCollection* TutorialPlayerInventory;
    UPROPERTY(BlueprintReadOnly)
    TMap<FGameplayTag, UInventoryItemsCollection*> LevelInventories;
    UPROPERTY(BlueprintReadOnly)
    UInventoryItemsCollection* RepairInventory;
    UPROPERTY(BlueprintReadOnly)
    TMap<FGameplayTag, UOpenedStashIDs*> OpenedStashes;
    UPROPERTY(BlueprintReadOnly)
    TArray<FString> SpawnedUniqueItems;
    UPROPERTY(BlueprintReadOnly)
    TArray<FStringToTagsList> WeaponAmmoBelts;
};
