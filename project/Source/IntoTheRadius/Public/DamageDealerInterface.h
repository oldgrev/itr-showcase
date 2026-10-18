#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DamageDealerInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UDamageDealerInterface : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IDamageDealerInterface {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FGameplayTag GetDamageDealerTag();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    FText GetDamageDealerName();

};
