#include "TagToItemConfigsList.h"

#include "ITRDefaults.h"
FTagToItemConfigsList::FTagToItemConfigsList() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("Tag.TagName"), TEXT("None"));
}

FTagToItemConfigsList::~FTagToItemConfigsList() {
}
