#include "MissionsConfig.h"
#include "ITRDefaults.h"

UMissionsConfig::UMissionsConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.MissionsConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("MaxExecuting"), (double)1);
}

UMissionsConfig* UMissionsConfig::GetMissionsConfig() {
    return {};
}

