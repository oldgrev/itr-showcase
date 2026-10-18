#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRBasicActor.h"
#include "ShopShowcase.generated.h"

class AActor;
class AShopSlot;
class USceneComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API AShopShowcase : public APRBasicActor {
    GENERATED_BODY()
public:
    AShopShowcase(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SwitchToIndex(int32 Index);

    UFUNCTION(BlueprintCallable)
    void SetUnlockedTypes(const TArray<FGameplayTag>& GameplayTag);

    UFUNCTION(BlueprintCallable)
    int32 GetSelectedIndex() const;

    UPROPERTY(BlueprintReadWrite)
    int32 CurrentConfigIndex;
    UPROPERTY(BlueprintReadWrite)
    int32 CurrentPhysicalIndex;
    UPROPERTY(BlueprintReadWrite)
    bool bSwitching;
    UPROPERTY(BlueprintReadWrite)
    float CurrentAngle;
    UPROPERTY(BlueprintReadWrite)
    float TargetAngle;
    UPROPERTY(BlueprintReadWrite)
    TArray<AShopSlot*> ShopSlots01;
    UPROPERTY(BlueprintReadWrite)
    TArray<AShopSlot*> ShopSlots02;
    UPROPERTY(BlueprintReadWrite)
    TArray<AShopSlot*> ShopSlots03;
    UPROPERTY(BlueprintReadWrite)
    TArray<AShopSlot*> ShopSlots04;
    UPROPERTY()
    USceneComponent* ItemInShowcaseRoot;
private:
    UPROPERTY()
    TMap<FGameplayTag, AActor*> ItemsInShowcase;
};
