#include "SpawnSlotData.h"

#include "ITRDefaults.h"
FSpawnSlotData::FSpawnSlotData() {
    IsEmpty = {};
    IsSpawned = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("IsEmpty"), true);
}

FSpawnSlotData::~FSpawnSlotData() {
}
