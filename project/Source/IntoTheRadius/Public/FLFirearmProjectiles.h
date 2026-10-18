#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AmmoInfo.h"
#include "ExplosionInfo.h"
#include "ExplosionParticalInfo.h"
#include "FLFirearmProjectiles.generated.h"

class AActor;
class APawn;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UFLFirearmProjectiles : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLFirearmProjectiles(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static void SpawnShrapnelProjectile(const FTransform& Transform, const FAmmoInfo AmmoInfo, const float Damage, const float AccuracyInternal, const float AccuracyMultiplier, const float Offset, const float TraceDistance, AActor* Owner, APawn* Instigator);

    UFUNCTION(BlueprintCallable)
    static void SpawnProjectile(const FTransform& Transform, const FAmmoInfo AmmoInfo, const float Damage, const float Velocity, const float AccuracyInternal, const float AccuracyMultiplier, const float Offset, AActor* Owner, APawn* Instigator, const bool IsForceTrace, bool& State, AActor*& Actor);

    UFUNCTION(BlueprintCallable)
    static void SpawnGrenadeProjectile(const FTransform& Transform, const FAmmoInfo& AmmoInfo, float Damage, float Velocity, float AccuracyRadians, AActor* Owner, APawn* Instigator, bool IsForceTrace);

    UFUNCTION(BlueprintCallable)
    static TArray<AActor*> SpawnExplosionProjectile(const FTransform& ExplosionOrigin, const FExplosionParticalInfo& ParticalInfo, AActor* Owner, APawn* Instigator, bool IsForceTrace);

    UFUNCTION(BlueprintCallable)
    static void SpawnExplosion(const FTransform& Transform, const FExplosionInfo ExplosionInfo, AActor* Owner, APawn* Instigator);

    UFUNCTION(BlueprintCallable)
    static void SpawnBulletProjectile(const FTransform& Transform, const FAmmoInfo& AmmoInfo, const float Damage, const float Velocity, const float AccuracyRadians, AActor* Owner, APawn* Instigator, const bool IsForceTrace, bool& State, AActor*& Actor);

};
