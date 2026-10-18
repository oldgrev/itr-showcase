#pragma once

#include "CoreMinimal.h"
#include "WPage.h"
#include "WMCPage_ShowcaseCategories.generated.h"

class UScrollBox;
class UWElement_ShowcaseCategory;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UWMCPage_ShowcaseCategories : public UWPage {
    GENERATED_BODY()
public:
    UWMCPage_ShowcaseCategories(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateSelection(int32 selectedIndex);

public:
    UFUNCTION(BlueprintCallable)
    void CheckForHasNewItems();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UScrollBox* SB_Categories;
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<UWElement_ShowcaseCategory*> ShowcaseCategoriesArray;
};
