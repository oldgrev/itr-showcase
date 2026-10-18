#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRBasicActor.h"
#include "EnvConfigurator.generated.h"

class AActor;
class ADirectionalLight;
class AExponentialHeightFog;
class ASkyLight;
class UCurveLinearColor;
class UParticleSystem;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API AEnvConfigurator : public APRBasicActor {
    GENERATED_BODY()
public:
    AEnvConfigurator(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag LevelTag;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    ADirectionalLight* Sun;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    AActor* Sky;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    ASkyLight* SkyLight;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    AExponentialHeightFog* Fog;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UParticleSystem* RainParticles;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    ADirectionalLight* ShadowLight;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UCurveLinearColor* ColorSun;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UCurveLinearColor* ColorFog;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UCurveLinearColor* ColorSky;
};
