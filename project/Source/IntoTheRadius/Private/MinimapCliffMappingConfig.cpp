#include "MinimapCliffMappingConfig.h"

#include "ITRDefaults.h"
FMinimapCliffMappingConfig::FMinimapCliffMappingConfig() {
    scaleThreshold = {};
    scaleRatio = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("scaleThreshold"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("scaleRatio"), (double)1);
}
