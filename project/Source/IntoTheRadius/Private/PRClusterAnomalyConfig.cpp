#include "PRClusterAnomalyConfig.h"

#include "ITRDefaults.h"
FPRClusterAnomalyConfig::FPRClusterAnomalyConfig() {
    Class = {};
    Radius = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Radius"), (double)400);
}
