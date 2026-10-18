#include "DialogueLine.h"

#include "ITRDefaults.h"
FDialogueLine::FDialogueLine() {
    Type = {};
    TimeNoAudio = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("TimeNoAudio"), (double)3);
}

FDialogueLine::~FDialogueLine() {
}
