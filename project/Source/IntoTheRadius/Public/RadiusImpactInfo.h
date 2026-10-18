#pragma once

#include "CoreMinimal.h"
#include "RadiusImpactInfo.generated.h"

class UMaterialInstance;
class UParticleSystem;
class UPrimitiveComponent;
class USoundBase;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRadiusImpactInfo {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    UParticleSystem* Template;
    UPROPERTY(BlueprintReadWrite)
    FVector ReflectionVector;
    UPROPERTY(BlueprintReadWrite)
    USoundBase* SoundCue;
    UPROPERTY(BlueprintReadWrite)
    float SoundDistance;
    UPROPERTY(BlueprintReadWrite)
    float SoundVolumnMultiplier;
    UPROPERTY(BlueprintReadWrite)
    float SoundDelay;
    UPROPERTY(BlueprintReadWrite)
    UMaterialInstance* DecalMaterial;
    UPROPERTY(BlueprintReadWrite)
    FVector DecalScale;
    UPROPERTY(BlueprintReadWrite)
    UPrimitiveComponent* AttachToComponent;
    FRadiusImpactInfo();
};
