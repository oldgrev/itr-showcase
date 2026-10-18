#pragma once

#include "CoreMinimal.h"
#include "PRPlayerControlsInterface.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UPRPlayerControlsInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IPRPlayerControlsInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GrabRight(const bool bPressed);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GrabLeft(const bool bPressed);

};
