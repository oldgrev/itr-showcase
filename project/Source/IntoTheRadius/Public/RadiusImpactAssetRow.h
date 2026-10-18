#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/DataTable.h"
#include "RadiusImpactAssetRow.generated.h"

class UMaterialInstance;
class UParticleSystem;
class USoundBase;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRadiusImpactAssetRow : public FTableRowBase {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TEnumAsByte<EPhysicalSurface> Surface;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UParticleSystem* Particle;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ParticleScale;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInstance* DEcal;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DecalScale;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    USoundBase* Sound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SoundDelay;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float VolumnMulti;
    FRadiusImpactAssetRow();
};
