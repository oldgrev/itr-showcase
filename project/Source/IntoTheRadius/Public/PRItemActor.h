#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "VRBPDatatypes.h"
#include "VRGripInterface.h"
#include "IPRItem.h"
#include "PRBasicActor.h"
#include "PRItemActor.generated.h"

class UBoxComponent;
class UInventoryItem;
class UPRItemDurabilityComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRItemActor : public APRBasicActor, public IVRGripInterface, public IGameplayTagAssetInterface, public IIPRItem {
    GENERATED_BODY()
public:
    APRItemActor(const FObjectInitializer& ObjectInitializer);

    virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

private:
    UPROPERTY()
    UInventoryItem* _inventoryItem;
public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UBoxComponent* ItemRootPrimitive;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UPRItemDurabilityComponent* DurabilityComponent;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag TypeID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FBPInterfaceProperties VRGripInterfaceSettings;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTagContainer GameplayTags;
};
