#include "PRClusterPatternConfig.h"

#include "ITRDefaults.h"
FPRClusterPatternConfig::FPRClusterPatternConfig() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("BlockExtent.X"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("BlockExtent.Y"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("BlockExtent.Z"), (double)100);
}

FPRClusterPatternConfig::~FPRClusterPatternConfig() {
}
