#include "GateInfo.h"

#include "ITRDefaults.h"
FGateInfo::FGateInfo() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeadsFrom.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("LeadsTo.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("UnlockTrigger.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("LocationInLevel.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LocationInLevel.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("LocationInLevel.Z"), (double)0);
}
