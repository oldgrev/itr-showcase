#include "RadiusHaptics.h"

#include "ITRDefaults.h"
FRadiusHaptics::FRadiusHaptics() {
    Type = {};
    Intensity = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Intensity"), (double)1);
}
