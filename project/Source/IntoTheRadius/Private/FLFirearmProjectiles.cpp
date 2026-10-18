#include "FLFirearmProjectiles.h"

UFLFirearmProjectiles::UFLFirearmProjectiles(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UFLFirearmProjectiles::SpawnShrapnelProjectile(const FTransform& Transform, const FAmmoInfo AmmoInfo, const float Damage, const float AccuracyInternal, const float AccuracyMultiplier, const float Offset, const float TraceDistance, AActor* Owner, APawn* Instigator) {
}

void UFLFirearmProjectiles::SpawnProjectile(const FTransform& Transform, const FAmmoInfo AmmoInfo, const float Damage, const float Velocity, const float AccuracyInternal, const float AccuracyMultiplier, const float Offset, AActor* Owner, APawn* Instigator, const bool IsForceTrace, bool& State, AActor*& Actor) {
}

void UFLFirearmProjectiles::SpawnGrenadeProjectile(const FTransform& Transform, const FAmmoInfo& AmmoInfo, float Damage, float Velocity, float AccuracyRadians, AActor* Owner, APawn* Instigator, bool IsForceTrace) {
}

TArray<AActor*> UFLFirearmProjectiles::SpawnExplosionProjectile(const FTransform& ExplosionOrigin, const FExplosionParticalInfo& ParticalInfo, AActor* Owner, APawn* Instigator, bool IsForceTrace) {
    return {};
}

void UFLFirearmProjectiles::SpawnExplosion(const FTransform& Transform, const FExplosionInfo ExplosionInfo, AActor* Owner, APawn* Instigator) {
}

void UFLFirearmProjectiles::SpawnBulletProjectile(const FTransform& Transform, const FAmmoInfo& AmmoInfo, const float Damage, const float Velocity, const float AccuracyRadians, AActor* Owner, APawn* Instigator, const bool IsForceTrace, bool& State, AActor*& Actor) {
}

