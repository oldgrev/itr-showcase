#pragma once

#include "CoreMinimal.h"
#include "Components/MeshComponent.h"
#include "PRAshMeshComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, EditInlineNew, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API UPRAshMeshComponent : public UMeshComponent {
    GENERATED_BODY()
public:
    UPRAshMeshComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void InitParticles();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpawnHeight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpawnRadius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LifeTimeMin;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LifeTimeMax;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ParticleSizeMin;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ParticleSizeMax;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ParticleSpeedMin;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ParticleSpeedMax;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ParticleAngularSpeedMax;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ParticleSpinRadiusMax;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ParticleSpinSpeedMax;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ParticlesCount;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ParticlesTileX;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ParticlesTileY;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor ParticleColorMin;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor ParticleColorMax;
};
