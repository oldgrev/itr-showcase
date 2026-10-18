#include "MinimapFoliageMappingConfig.h"

#include "ITRDefaults.h"
FMinimapFoliageMappingConfig::FMinimapFoliageMappingConfig() {
    Scale = {};
    rotateToMesh = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Scale"), (double)1);
}

FMinimapFoliageMappingConfig::~FMinimapFoliageMappingConfig() {
}
