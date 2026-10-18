#pragma once

#include "CoreMinimal.h"
#include "EDamageCategory.h"
#include "IDamageCategory.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UIDamageCategory : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIDamageCategory {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    EDamageCategory GetDamageCategory() const;

};
