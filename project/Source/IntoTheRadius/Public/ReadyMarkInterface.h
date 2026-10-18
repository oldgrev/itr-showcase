#pragma once

#include "CoreMinimal.h"
#include "ReadyMarkInterface.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UReadyMarkInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IReadyMarkInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool ReadyTrigger() const;

};
