#include "TagToItemConfig.h"

#include "ITRDefaults.h"
FTagToItemConfig::FTagToItemConfig() {
    Config = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Tag.TagName"), TEXT("None"));
}
