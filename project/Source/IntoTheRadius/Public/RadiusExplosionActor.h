#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "GameFramework/Actor.h"
#include "ExplosionInfo.h"
#include "IPooledActor.h"
#include "IRadiusExplosionActor.h"
#include "RadiusExplosionActor.generated.h"

class UDamageType;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API ARadiusExplosionActor : public AActor, public IIRadiusExplosionActor, public IIPooledActor {
    GENERATED_BODY()
public:
    ARadiusExplosionActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetTriggerMaxRange(const float MaxRange);

    UFUNCTION(BlueprintCallable)
    const FExplosionInfo& GetExplosionInfo() const;

protected:
    UPROPERTY(EditDefaultsOnly)
    int32 MaxIteration;
    UPROPERTY(EditDefaultsOnly)
    float Strength;
    UPROPERTY(EditDefaultsOnly)
    TEnumAsByte<ERadialImpulseFalloff> Fallout;
    UPROPERTY(EditDefaultsOnly)
    bool IsVelocityChange;
    UPROPERTY(EditDefaultsOnly)
    float MaxWallDistance;
    UPROPERTY(EditDefaultsOnly)
    FName TraceProfileName;
    UPROPERTY(EditDefaultsOnly)
    float DamageMinRange;
    UPROPERTY(EditDefaultsOnly)
    float MaxDamageScale;
    UPROPERTY(EditDefaultsOnly)
    float HitMinDistance;
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UDamageType> DamageClass;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float ExplosionRadius;
    UPROPERTY(EditDefaultsOnly)
    FVector2D WallScaleIn;
    UPROPERTY(EditDefaultsOnly)
    FVector2D WallScaleOut;
    UPROPERTY(EditDefaultsOnly)
    float WallRangeMin;
};
