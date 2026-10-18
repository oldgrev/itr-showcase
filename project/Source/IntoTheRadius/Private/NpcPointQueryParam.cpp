#include "NpcPointQueryParam.h"

#include "ITRDefaults.h"
FNpcPointQueryParam::FNpcPointQueryParam() {
    NpcCharacterRef = {};
    SearchRadius = {};
    MinDistanceToCenter = {};
    bDoPathLengthCheck = {};
    MaxPathLength = {};
    bDoSquadDistanceCheck = {};
    MinSquadDistance = {};
    MaxSearchIteration = {};
    bAlwaysMoveTowardsDesiredLocation = {};
    bUseDistantPointAsQueryCenter = {};
    bForceFastPointSearch = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("SearchCenter.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SearchCenter.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SearchCenter.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("SearchRadius"), (double)4000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DesiredLocation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DesiredLocation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DesiredLocation.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MinDistanceToCenter"), (double)100);
    ITRDefaults::Set(StaticStruct(), this, TEXT("bDoPathLengthCheck"), true);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MaxPathLength"), (double)1000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("bDoSquadDistanceCheck"), true);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MinSquadDistance"), (double)2000);
    ITRDefaults::Set(StaticStruct(), this, TEXT("MaxSearchIteration"), (double)1);
}
