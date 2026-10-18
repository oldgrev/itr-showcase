#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PRBasicActor.h"
#include "PREnvironment.generated.h"

class ADirectionalLight;
class ALevelSequenceActor;
class APRSkyBox;
class APostProcessVolume;
class ASkyLight;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API APREnvironment : public APRBasicActor {
    GENERATED_BODY()
public:
    APREnvironment(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void Startup();

public:
    UFUNCTION(BlueprintCallable)
    void SetEnvironmentHidden(const bool bEnvironmentHidden);

private:
    UFUNCTION()
    void OnGameTimeChanged(float AddedSeconds);

    UFUNCTION()
    void OnGameplayTimeDilationChanged(float Dilation);

public:
    UFUNCTION(BlueprintCallable)
    FVector GetRadiusLocation() const;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag EnvironmentLevelTag;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    APRSkyBox* SkyBoxRef;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ALevelSequenceActor* EnvLevelSequenceRef;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ADirectionalLight* SunRef;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ASkyLight* SkyLightRef;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    APostProcessVolume* LightScenarioPostProcessRef;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DebugTimeScale;
};
