#include "PRAshMeshComponent.h"
#include "ITRDefaults.h"

UPRAshMeshComponent::UPRAshMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("SpawnHeight"), (double)500);
    ITRDefaults::Set(GetClass(), this, TEXT("SpawnRadius"), (double)4000);
    ITRDefaults::Set(GetClass(), this, TEXT("LifeTimeMin"), (double)12);
    ITRDefaults::Set(GetClass(), this, TEXT("LifeTimeMax"), (double)20);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleSizeMin"), (double)2);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleSizeMax"), (double)5);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleSpeedMin"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleSpeedMax"), (double)55);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleAngularSpeedMax"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleSpinRadiusMax"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleSpinSpeedMax"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticlesCount"), (double)2048);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticlesTileX"), (double)3);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticlesTileY"), (double)3);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleColorMin.R"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleColorMin.G"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleColorMin.B"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleColorMin.A"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleColorMax.R"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleColorMax.G"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleColorMax.B"), (double)1);
    ITRDefaults::Set(GetClass(), this, TEXT("ParticleColorMax.A"), (double)1);
}

void UPRAshMeshComponent::InitParticles() {
}

