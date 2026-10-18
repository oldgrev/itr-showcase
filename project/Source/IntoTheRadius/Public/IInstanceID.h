#pragma once

#include "CoreMinimal.h"
#include "IInstanceID.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIInstanceID : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIInstanceID {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FString GetInstanceID();

};
