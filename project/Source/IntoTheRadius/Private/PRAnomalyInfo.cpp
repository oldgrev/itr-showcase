#include "PRAnomalyInfo.h"

#include "ITRDefaults.h"
FPRAnomalyInfo::FPRAnomalyInfo() {
    ActorClass = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("TypeID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("RadiusRange.Min"), (double)400);
    ITRDefaults::Set(StaticStruct(), this, TEXT("RadiusRange.Max"), (double)400);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DamageRange.Min"), (double)10);
    ITRDefaults::Set(StaticStruct(), this, TEXT("DamageRange.Max"), (double)10);
}

FPRAnomalyInfo::~FPRAnomalyInfo() {
}
