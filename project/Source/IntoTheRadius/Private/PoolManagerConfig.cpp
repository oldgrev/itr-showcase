#include "PoolManagerConfig.h"
#include "ITRDefaults.h"

UPoolManagerConfig::UPoolManagerConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.PoolManagerConfig"));
}

UPoolManagerConfig* UPoolManagerConfig::GetPoolManagerConfig() {
    return {};
}

