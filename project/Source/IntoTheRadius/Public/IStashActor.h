#pragma once

#include "CoreMinimal.h"
#include "StashSpawnInfo.h"
#include "IStashActor.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UIStashActor : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IIStashActor {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent)
    void Setup(const FStashSpawnInfo& StashSpawnInfo);

};
