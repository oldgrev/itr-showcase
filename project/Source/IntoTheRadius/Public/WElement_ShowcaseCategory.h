#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WElement_ShowcaseCategory.generated.h"

class UImage;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UWElement_ShowcaseCategory : public UUserWidget {
    GENERATED_BODY()
public:
    UWElement_ShowcaseCategory(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ShowNewItemExclamationMark(bool bShow);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UImage* Exclamation_Mark;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UImage* Image_Selected;
};
