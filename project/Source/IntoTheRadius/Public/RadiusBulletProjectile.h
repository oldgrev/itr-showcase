#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "RadiusProjectile.h"
#include "RadiusBulletProjectile.generated.h"

class AActor;
class UPrimitiveComponent;
class URadiusBulletComponent;
class URadiusBulletImpulseComponent;
class URadiusBulletTracerComponent;
class USphereComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusBulletProjectile : public ARadiusProjectile {
    GENERATED_BODY()
public:
    ARadiusBulletProjectile(const FObjectInitializer& ObjectInitializer);

    UFUNCTION()
    void SphereColliderHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

    UFUNCTION(BlueprintImplementableEvent)
    void OnSpawnImpact(const FHitResult& Hit, const float Scale);

    UFUNCTION()
    void BulletComponentRicochet(const FVector& Location, const FVector& Force, const bool IsPenetration);

    UFUNCTION()
    void BulletComponentImpact(const FHitResult& Hit);

protected:
    UPROPERTY(BlueprintReadOnly)
    float BaseDamage;
    UPROPERTY(VisibleDefaultsOnly)
    USphereComponent* SphereCollider;
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
    URadiusBulletTracerComponent* BulletTracerComponent;
    UPROPERTY(VisibleDefaultsOnly)
    URadiusBulletComponent* BulletComponent;
    UPROPERTY(VisibleDefaultsOnly)
    URadiusBulletImpulseComponent* BulletImpulseComponent;
    UPROPERTY(EditDefaultsOnly)
    bool DebugMode;
    UPROPERTY(EditDefaultsOnly)
    FVector2D ParticalScaleInputRange;
    UPROPERTY(EditDefaultsOnly)
    FVector2D ParticalScaleOutputRange;
};
