#pragma once

#include "CoreMinimal.h"
#include "IClearable.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIClearable : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIClearable {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void Clear();

};
