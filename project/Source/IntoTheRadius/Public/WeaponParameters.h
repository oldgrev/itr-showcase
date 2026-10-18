#pragma once

#include "CoreMinimal.h"
#include "EWeaponFireMode.h"
#include "WeaponParameters.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FWeaponParameters {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float FireRate;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float ShotLoudness;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float MuzzleVelocity;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AmmoDamage;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DurabilityDamagePerShot;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DurabilityDamageAutoFireCoefficient;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float Reliability;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UCurveFloat* JamCurve;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool bDisableSmoothing;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float TwoHandSmoothingAlpha;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float TwoHandSmoothingDistance;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<EWeaponFireMode> FireModes;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 BurstModeCount;
    FWeaponParameters();
    ~FWeaponParameters();
};
