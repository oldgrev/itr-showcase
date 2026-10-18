#pragma once

#include "CoreMinimal.h"
#include "BulletImpulseWhistleDelegate.h"
#include "PRBasicActorComponent.h"
#include "RadiusBulletImpulseComponent.generated.h"

class UCurveFloat;
class UPrimitiveComponent;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS_API URadiusBulletImpulseComponent : public UPRBasicActorComponent {
    GENERATED_BODY()
public:
    URadiusBulletImpulseComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void Suspend(bool IsSuspend);

    UFUNCTION(BlueprintCallable)
    void Stop();

    UFUNCTION(BlueprintCallable)
    void Start();

    UFUNCTION(BlueprintCallable)
    void Ricochet(const FVector& Location, const FVector& Force, const bool IsPenetration);

    UFUNCTION(BlueprintCallable)
    void Initialize(UPrimitiveComponent* TargetComponent, const float Mass, const float InitialVelocity, UCurveFloat* SpeedCurve);

private:
    UPROPERTY()
    UPrimitiveComponent* _target;
    UPROPERTY()
    UCurveFloat* _speedCurve;
protected:
    UPROPERTY(EditDefaultsOnly)
    float DistanceDivider;
public:
    UPROPERTY(BlueprintAssignable)
    FBulletImpulseWhistle OnWhistleEvent;
};
