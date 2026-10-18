#include "MissionsCategory.h"

#include "ITRDefaults.h"
FMissionsCategory::FMissionsCategory() {
    MaxSimultaneously = {};
    RestrictMaxSuccessfulPerTide = {};
    OnceInALife = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("CategoryID.TagName"), TEXT("None"));
}

FMissionsCategory::~FMissionsCategory() {
}
