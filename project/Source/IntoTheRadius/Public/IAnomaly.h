#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRAnomalyInfo.h"
#include "IAnomaly.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIAnomaly : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIAnomaly {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FGameplayTag GetTypeID() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetRadius() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetBaseDamage() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FPRAnomalyInfo GetAnomalyInfo() const;

};
