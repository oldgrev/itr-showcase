#include "RadiusEmitterVectorParameter.h"

#include "ITRDefaults.h"
FRadiusEmitterVectorParameter::FRadiusEmitterVectorParameter() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("Value.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Value.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Value.Z"), (double)0);
}
