#pragma once

#include "CoreMinimal.h"
#include "PlayerLightSensitiveInterface.generated.h"

class USceneComponent;

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UPlayerLightSensitiveInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IPlayerLightSensitiveInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void LightOn(FVector Location, USceneComponent* Component);

};
