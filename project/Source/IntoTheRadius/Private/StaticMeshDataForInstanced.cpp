#include "StaticMeshDataForInstanced.h"

#include "ITRDefaults.h"
FStaticMeshDataForInstanced::FStaticMeshDataForInstanced() {
    CountOfStaticMeshInstances = {};
    MaxCullDistance = {};
    EnableCollisionOverlapEvents = {};
    ComponentMobility = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("LocationsAccumulated.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LocationsAccumulated.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LocationsAccumulated.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("CollisionProfileName"), TEXT("BlockAll"));
}

FStaticMeshDataForInstanced::~FStaticMeshDataForInstanced() {
}
