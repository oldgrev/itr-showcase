#pragma once

#include "CoreMinimal.h"
#include "IPRGameModeNative.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIPRGameModeNative : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIPRGameModeNative {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool GetIsInTransition() const;

};
