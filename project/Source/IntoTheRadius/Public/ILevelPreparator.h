#pragma once

#include "CoreMinimal.h"
#include "ILevelPreparator.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UILevelPreparator : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IILevelPreparator {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool IsPreparing();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    bool CheckPreparator(FVector Location);

};
