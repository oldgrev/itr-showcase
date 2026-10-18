#pragma once

#include "CoreMinimal.h"
#include "IngameMenuControllerInterface.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIngameMenuControllerInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIngameMenuControllerInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SwitchIngameMenu();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsIngameMenuActive() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GetPreMenuParameters(FTransform& preMenuTransform, FVector& preMenuVelocity);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void CloseIngameMenu();

};
