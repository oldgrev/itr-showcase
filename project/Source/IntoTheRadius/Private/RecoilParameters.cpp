#include "RecoilParameters.h"

#include "ITRDefaults.h"
FRecoilParameters::FRecoilParameters() {
    OverallRecoilInfoPercent = {};
    RecoilAutoFireCoefficient = {};
    RecoilLocationAutoFireCoefficient = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilLocationOffset.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilLocationOffset.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RecoilLocationOffset.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("StabilizedRecoilLocationOffset.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("StabilizedRecoilLocationOffset.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("StabilizedRecoilLocationOffset.Z"), (double)0);
}
