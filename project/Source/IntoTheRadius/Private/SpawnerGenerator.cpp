#include "SpawnerGenerator.h"
#include "ITRDefaults.h"

ASpawnerGenerator::ASpawnerGenerator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.EndTickGroup"), (double)0);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bTickEvenWhenPaused"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bCanEverTick"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bStartWithTickEnabled"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("PrimaryActorTick.TickInterval"), (double)0.200000003);
    ITRDefaults::Set(GetClass(), this, TEXT("generatorID.TagName"), TEXT("None"));
    ITRDefaults::Set(GetClass(), this, TEXT("CooldownSeconds"), (double)30);
    ITRDefaults::Set(GetClass(), this, TEXT("HitPoints"), (double)10);
}

void ASpawnerGenerator::StopGenerator() {
}

bool ASpawnerGenerator::Special() const {
    return {};
}

void ASpawnerGenerator::SaveGeneratorData() {
}

void ASpawnerGenerator::CallSpawner(AMonsterSpawner* Spawner, bool& bSuccess, AActor*& NPCActor) {
}

