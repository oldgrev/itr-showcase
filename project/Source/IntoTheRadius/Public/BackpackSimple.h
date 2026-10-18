#pragma once

#include "CoreMinimal.h"
#include "GrippableStaticMeshActor.h"
#include "IPRItem.h"
#include "BackpackSimple.generated.h"

class APRHolder;
class USceneComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ABackpackSimple : public AGrippableStaticMeshActor, public IIPRItem {
    GENERATED_BODY()
public:
    ABackpackSimple(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void RefreshState();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnUnequipped();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnReturned();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void LerpToHolster();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    const USceneComponent* GetPivotGripPoint() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    APRHolder* GetHolderSleepingBag();

    UFUNCTION(BlueprintCallable)
    TArray<APRHolder*> GetHolders();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    APRHolder* GetHolderPrimaryWeapon();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    APRHolder* GetHolderBackpack();

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    bool CheckEquipped() const;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<APRHolder*> Holders;
};
