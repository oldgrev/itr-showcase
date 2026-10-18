#pragma once

#include "CoreMinimal.h"
#include "PRBasicActor.h"
#include "PRSplashDesc.h"
#include "PRTransitionHint.generated.h"

class USceneComponent;
class UWidgetComponent;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API APRTransitionHint : public APRBasicActor {
    GENERATED_BODY()
public:
    APRTransitionHint(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ShowTransitionHint();

    UFUNCTION(BlueprintCallable)
    void HideTransitionHint();

protected:
    UPROPERTY(EditDefaultsOnly)
    USceneComponent* Root;
    UPROPERTY(EditDefaultsOnly)
    USceneComponent* HintWidgetParentComponent;
    UPROPERTY(EditDefaultsOnly)
    UWidgetComponent* HintWidgetComponent;
    UPROPERTY(EditDefaultsOnly)
    TArray<FPRSplashDesc> SplashDescriptions_Quest;
    UPROPERTY(EditDefaultsOnly)
    FPRSplashDesc SplashDescForHint_Quest;
    UPROPERTY(EditDefaultsOnly)
    TArray<FPRSplashDesc> SplashDescriptions_Pico;
    UPROPERTY(EditDefaultsOnly)
    FPRSplashDesc SplashDescForHint_Pico;
};
