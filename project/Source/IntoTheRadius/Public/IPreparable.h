#pragma once

#include "CoreMinimal.h"
#include "IPreparable.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIPreparable : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIPreparable {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void Prepare();

};
