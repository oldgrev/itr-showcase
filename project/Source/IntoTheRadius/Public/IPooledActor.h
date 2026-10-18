#pragma once

#include "CoreMinimal.h"
#include "IPooledActor.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIPooledActor : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIPooledActor {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent)
    void PushToPoolActor();

    UFUNCTION(BlueprintNativeEvent)
    void PopFromPoolActor(const FTransform Transform);

    UFUNCTION(BlueprintNativeEvent)
    bool IsExcludedFromPool();

};
