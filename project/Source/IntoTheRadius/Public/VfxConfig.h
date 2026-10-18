#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IAsset.h"
#include "VfxConfig.generated.h"

class AActor;
class UDataTable;
class USoundAttenuation;
class USoundBase;
class UVfxConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UVfxConfig : public UDataAsset, public IIAsset {
    GENERATED_BODY()
public:
    UVfxConfig(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    static UVfxConfig* GetVfxConfig();

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<AActor> ImpactClass;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<AActor> EmitterClass;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<AActor> NiagaraEmitterClass;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector2D ImpactDistanceClampInRange;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector2D ImpactDistanceClampOutRange;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FString ImpactDisableFlag;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UDataTable* ImpactsTables;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName ImpactDefaultRow;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector ImpactDefaultDecalScale;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float ImpactDefaultVolumnMulti;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    USoundBase* ImpactDefaultSound;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    USoundAttenuation* ImpactDefaultAttenuation;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector ImpactOffsetVector;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float ImpactSpeedScale;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float BulletTracersStartDelay;
};
