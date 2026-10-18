#include "AmmoConfig.h"
#include "ITRDefaults.h"

UAmmoConfig::UAmmoConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.AmmoConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("MeshPrimitiveDataIndex"), (double)6);
    ITRDefaults::Set(GetClass(), this, TEXT("ProjectileForwardSpawnOffset"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("AirExplosionShrapnelAccuracyRange.X"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("AirExplosionShrapnelAccuracyRange.Y"), (double)6.28000021);
    ITRDefaults::Set(GetClass(), this, TEXT("AirExplosionBulletAccuracyRange.X"), (double)2.79999995);
    ITRDefaults::Set(GetClass(), this, TEXT("AirExplosionBulletAccuracyRange.Y"), (double)6.28000021);
    ITRDefaults::Set(GetClass(), this, TEXT("ExplosionProjectilesOriginOffset.X"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ExplosionProjectilesOriginOffset.Y"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("ExplosionProjectilesOriginOffset.Z"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("ExplosionProjectilesBoxExtend.X"), (double)20);
    ITRDefaults::Set(GetClass(), this, TEXT("ExplosionProjectilesBoxExtend.Y"), (double)20);
    ITRDefaults::Set(GetClass(), this, TEXT("ExplosionProjectilesBoxExtend.Z"), (double)10);
}

void UAmmoConfig::SetupAmmoMeshComponent(const FGameplayTag& AmmoTag, UStaticMeshComponent* AmmoMeshComponent, const bool IsFired) {
}

bool UAmmoConfig::IsTakenOutAmmo(AActor* Actor) {
    return {};
}

bool UAmmoConfig::IsShrapnelAmmo(FGameplayTag AmmoTag) {
    return {};
}

bool UAmmoConfig::IsHeldAmmo(AActor* Actor) {
    return {};
}

bool UAmmoConfig::IsAmmo(const AActor* Actor) {
    return {};
}

UStaticMesh* UAmmoConfig::GetAmmoWholeMesh(const FGameplayTag& AmmoType) {
    return {};
}

FText UAmmoConfig::GetAmmoTypeName(const FGameplayTag& AmmoType) {
    return {};
}

FLinearColor UAmmoConfig::GetAmmoTypeColor(const FGameplayTag& AmmoType) {
    return {};
}

UAmmoConfig* UAmmoConfig::GetAmmoTagsConfig() {
    return {};
}

UStaticMesh* UAmmoConfig::GetAmmoShellMesh(const FGameplayTag& AmmoType) {
    return {};
}

