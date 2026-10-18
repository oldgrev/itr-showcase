#pragma once

#include "CoreMinimal.h"
#include "ILootSpawner.generated.h"

UINTERFACE(Blueprintable)
class INTOTHERADIUS_API UILootSpawner : public UInterface {
    GENERATED_BODY()
};

class INTOTHERADIUS_API IILootSpawner {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void SpawnLoot();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void GenerateLoot();

};
