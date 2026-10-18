#include "MinimapMeshMappingConfig.h"

#include "ITRDefaults.h"
FMinimapMeshMappingConfig::FMinimapMeshMappingConfig() {
    Scale = {};
    rotateToMesh = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Scale"), (double)1);
}

FMinimapMeshMappingConfig::~FMinimapMeshMappingConfig() {
}
