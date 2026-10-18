#include "TagToTagsList.h"

#include "ITRDefaults.h"
FTagToTagsList::FTagToTagsList() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("Tag.TagName"), TEXT("None"));
}

FTagToTagsList::~FTagToTagsList() {
}
