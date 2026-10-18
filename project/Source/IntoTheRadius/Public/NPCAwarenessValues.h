#pragma once

#include "CoreMinimal.h"
#include "NPCAwarenessValues.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FNPCAwarenessValues {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float NoiseFootsteps;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float NoiseWeaponSounds;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float NoiseWeaponShot;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float DamageMultiplier;
    FNPCAwarenessValues();
};
