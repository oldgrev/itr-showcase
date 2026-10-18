#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ComputerPage.h"
#include "WPage.generated.h"

class UTextBlock;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UWPage : public UUserWidget, public IComputerPage {
    GENERATED_BODY()
public:
    UWPage(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateFooterTexts(UTextBlock* textPlayerLevel, UTextBlock* textMoney, UTextBlock* textTime);

};
