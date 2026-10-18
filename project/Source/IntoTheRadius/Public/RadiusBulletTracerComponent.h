#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameplayTagContainer.h"
#include "RadiusBulletTracerComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API URadiusBulletTracerComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    URadiusBulletTracerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void Suspend(bool IsSuspend);

    UFUNCTION(BlueprintCallable)
    void Stop();

    UFUNCTION(BlueprintCallable)
    void Start();

    UFUNCTION(BlueprintCallable)
    void Initialize(const bool ForceTracer, const float MinSpeed, const float MaxSpeed, const FGameplayTag AmmoTypeID, const bool DebugMode);

private:
    UFUNCTION()
    void DelayedStart();

protected:
    UPROPERTY(EditDefaultsOnly)
    FGameplayTag TracerTag;
    UPROPERTY(EditDefaultsOnly)
    FLinearColor DebugPrimaryColor;
    UPROPERTY(EditDefaultsOnly)
    FLinearColor DebugSecondaryColor;
    UPROPERTY(EditDefaultsOnly)
    float DebugLineDurarion;
    UPROPERTY(EditDefaultsOnly)
    float DebugLineThickness;
    UPROPERTY(EditDefaultsOnly)
    float ScaleFactor;
    UPROPERTY(EditDefaultsOnly)
    FVector2D ScaleFactorInputRange;
    UPROPERTY(EditDefaultsOnly)
    FVector2D ScaleFactorOutputRange;
    UPROPERTY(EditDefaultsOnly)
    float VelocityTolerance;
};
