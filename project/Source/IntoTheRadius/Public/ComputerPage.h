#pragma once

#include "CoreMinimal.h"
#include "ComputerPage.generated.h"

class AActor;

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UComputerPage : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IComputerPage {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ShowPage();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void PageTick();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void InitializeByActor(AActor* Actor);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void HidePage();

};
