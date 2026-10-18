#pragma once

#include "CoreMinimal.h"
#include "DistanceGripCandidate.h"
#include "DistanceGripManager.generated.h"

class APRPlayerCharacter;
class UInventoryItem;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UDistanceGripManager : public UObject {
    GENERATED_BODY()
public:
    UDistanceGripManager(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION()
    void LevelTransitionStartCallback();

    UFUNCTION()
    void LevelTransitionEndCallback();

    UFUNCTION()
    void ItemTakenFromLevelCallback(UInventoryItem* ItemTaken);

    UFUNCTION()
    void ItemStoredToLevelCallback(UInventoryItem* ItemStored);

    UFUNCTION()
    void ItemRemovedFromLevelCallback(UInventoryItem* ItemRemoved);

    UFUNCTION()
    void ItemActorRemovedCallback(UInventoryItem* ItemWithActorRemoved);

    UPROPERTY()
    APRPlayerCharacter* GripSystemOwner;
    UPROPERTY()
    TMap<UInventoryItem*, FDistanceGripCandidate> CandidatePool;
};
