#include "ConditionalPaperNote.h"

#include "ITRDefaults.h"
FConditionalPaperNote::FConditionalPaperNote() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("NoteID.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("Group"), (double)3);
}

FConditionalPaperNote::~FConditionalPaperNote() {
}
