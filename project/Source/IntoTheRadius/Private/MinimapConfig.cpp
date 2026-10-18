#include "MinimapConfig.h"
#include "ITRDefaults.h"

UMinimapConfig::UMinimapConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.MinimapConfig"));
    ITRDefaults::Set(GetClass(), this, TEXT("treeRadius"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("waterScanStep"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("waterRadius"), (double)10);
    ITRDefaults::Set(GetClass(), this, TEXT("waterMinDeph"), (double)50);
    ITRDefaults::Set(GetClass(), this, TEXT("MapImageOversize"), (double)1.10000002);
    ITRDefaults::Set(GetClass(), this, TEXT("MapImageSize"), (double)4096);
}

