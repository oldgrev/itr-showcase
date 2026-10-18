#include "PRLootSpawner.h"
#include "ITRDefaults.h"

APRLootSpawner::APRLootSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("InstanceIdPrefix"), TEXT("LootSpawner-"));
    ITRDefaults::Set(GetClass(), this, TEXT("TryProject"), true);
    ITRDefaults::Set(GetClass(), this, TEXT("LootPoints"), (double)3);
    ITRDefaults::Set(GetClass(), this, TEXT("LootTable.TagName"), TEXT("None"));
}

void APRLootSpawner::OnCheckDistanceTick() {
}

