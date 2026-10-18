#include "Mantle_Asset.h"

#include "ITRDefaults.h"
FMantle_Asset::FMantle_Asset() {
    AnimMontage = {};
    PositionOrCorrectionCurve = {};
    LowHeight = {};
    LowPlayRate = {};
    LowStartPosition = {};
    HighHeight = {};
    HighPlayRate = {};
    HighStartPosition = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("StartingOffset.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("StartingOffset.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("StartingOffset.Z"), (double)0);
}
