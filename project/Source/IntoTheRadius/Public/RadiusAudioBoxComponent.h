#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Sound/AudioVolume.h"
#include "Sound/ReverbSettings.h"
#include "RadiusAudioBoxComponent.generated.h"

class AActor;
class AAudioVolume;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API URadiusAudioBoxComponent : public UBoxComponent {
    GENERATED_BODY()
public:
    URadiusAudioBoxComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void UpdateVolumeSettings();

public:
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);

    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool bNewEnabled);

protected:
    UFUNCTION()
    void OnOwnerDestroyed(AActor* DestoryedObject);

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
    float Priority;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
    uint8 bEnabled : 1;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
    FReverbSettings Settings;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
    FInteriorSettings AmbientZoneSettings;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
    TArray<FAudioVolumeSubmixSendSettings> SubmixSendSettings;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
    TArray<FAudioVolumeSubmixOverrideSettings> SubmixOverrideSettings;
protected:
    UPROPERTY(VisibleInstanceOnly)
    AAudioVolume* CachedVolume;
};
