#include "PaperNote.h"

#include "ITRDefaults.h"
FPaperNote::FPaperNote() {
    Group = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("NoteID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("Group"), (double)3);
}

FPaperNote::~FPaperNote() {
}
