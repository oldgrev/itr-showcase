#include "TagToTagTuplesList.h"

#include "ITRDefaults.h"
FTagToTagTuplesList::FTagToTagTuplesList() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("Tag.TagName"), TEXT("None"));
}
