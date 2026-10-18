#include "PRTriggerConfig.h"

#include "ITRDefaults.h"
FPRTriggerConfig::FPRTriggerConfig() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("Trigger.TagName"), TEXT("None"));
}

FPRTriggerConfig::~FPRTriggerConfig() {
}
