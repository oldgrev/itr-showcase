#include "PoolActorConfig.h"

#include "ITRDefaults.h"
FPoolActorConfig::FPoolActorConfig() {
    ActorClass = {};
    InitCount = {};
    MaxCount = {};
    ReCreateOnDestroy = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("MaxCount"), (double)100);
}

FPoolActorConfig::~FPoolActorConfig() {
}
