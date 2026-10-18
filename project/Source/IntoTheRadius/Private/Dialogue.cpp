#include "Dialogue.h"

#include "ITRDefaults.h"
FDialogue::FDialogue() {
    Group = {};
    Sound = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Group"), (double)3);
}

FDialogue::~FDialogue() {
}
