#pragma once

#include "CoreMinimal.h"
#include "DistanceGripCandidate.generated.h"

class AGrippableStaticMeshActor;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FDistanceGripCandidate {
    GENERATED_BODY()

private:
    UPROPERTY()
    AGrippableStaticMeshActor* Actor;
    UPROPERTY()
    UPrimitiveComponent* Component;
public:
    FDistanceGripCandidate();
};
