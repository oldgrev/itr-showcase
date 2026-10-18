#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "WShopComputer.generated.h"

class AActor;
class UWMCPage_ShowcaseCategories;
class UWPage;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UWShopComputer : public UUserWidget {
    GENERATED_BODY()
public:
    UWShopComputer(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateNewItems();

    UFUNCTION(BlueprintCallable)
    void ShowTakeItems(bool bShow);

    UFUNCTION(BlueprintCallable)
    void ShowShopBin(bool bShow);

private:
    UFUNCTION()
    void OnSCTick();

    UFUNCTION()
    void OnLevelStarted(FGameplayTag LevelTag);

    UFUNCTION()
    void OnGameStarted();

public:
    UFUNCTION(BlueprintCallable)
    bool IsShopBinVisible() const;

    UFUNCTION(BlueprintCallable)
    void InitializeByActor(AActor* Actor);

    UPROPERTY()
    UWPage* WMCPage_Empty;
    UPROPERTY()
    UWPage* WMCPage_ShopBin;
    UPROPERTY()
    UWPage* WMCPage_ShopControls;
    UPROPERTY()
    UWMCPage_ShowcaseCategories* WMCPage_ShowcaseCategories;
    UPROPERTY()
    UWPage* WMCPage_TakeItems;
};
