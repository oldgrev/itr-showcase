#include "NpcPointQueryResult.h"

#include "ITRDefaults.h"
FNpcPointQueryResult::FNpcPointQueryResult() {
    bPointFound = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Point.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Point.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Point.Z"), (double)0);
}

FNpcPointQueryResult::~FNpcPointQueryResult() {
}
