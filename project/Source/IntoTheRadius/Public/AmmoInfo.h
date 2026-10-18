#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "AmmoInfo.generated.h"

class UCurveFloat;
class UDamageType;
class UStaticMesh;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FAmmoInfo : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag ItemTypeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag AmmoCaliberID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FGameplayTag AmmoTypeID;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UStaticMesh* ShellMesh;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UStaticMesh* WholeMesh;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool ShortInfo;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float VelocityMultiplier;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TSubclassOf<UDamageType> DamageType;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float Penetration;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 BounceMax;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float ArmorPiercing;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DamageModifier;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UCurveFloat* SpeedDropCurve;
    FAmmoInfo();
    ~FAmmoInfo();
};
