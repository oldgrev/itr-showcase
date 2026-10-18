#include "NoteData.h"

#include "ITRDefaults.h"
FNoteData::FNoteData() {
    Group = {};
    Image = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("ID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("Group"), (double)3);
}

FNoteData::~FNoteData() {
}
