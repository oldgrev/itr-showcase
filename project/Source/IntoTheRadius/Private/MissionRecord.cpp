#include "MissionRecord.h"

#include "ITRDefaults.h"
FMissionRecord::FMissionRecord() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("Tag.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("Weapon.TagName"), TEXT("None"));
}

FMissionRecord::~FMissionRecord() {
}
