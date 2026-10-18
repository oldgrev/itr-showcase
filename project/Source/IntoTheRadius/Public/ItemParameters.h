#pragma once

#include "CoreMinimal.h"
#include "ItemParameters.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FItemParameters {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UStaticMesh* MeshOverride;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float Weight;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float Durability;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DurabilityDamageCoefficient;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DurabilityDamagePerHour;
    FItemParameters();
};
