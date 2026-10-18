#include "Mantle_Params.h"

#include "ITRDefaults.h"
FMantle_Params::FMantle_Params() {
    AnimMontage = {};
    PositionOrCorrectionCurve = {};
    StartingPosition = {};
    PlayRate = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("StartingOffset.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("StartingOffset.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("StartingOffset.Z"), (double)0);
}
