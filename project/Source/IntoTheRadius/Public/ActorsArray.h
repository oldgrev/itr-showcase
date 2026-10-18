#pragma once

#include "CoreMinimal.h"
#include "ActorsArray.generated.h"

class AActor;
class UObject;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FActorsArray {
    GENERATED_BODY()

private:
    UPROPERTY()
    TArray<AActor*> Actors;
    UPROPERTY()
    TArray<bool> InUseFlags;
public:
    UPROPERTY()
    UObject* WorldContext;
    FActorsArray();
    ~FActorsArray();
};
