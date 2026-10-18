#include "Record.h"

#include "ITRDefaults.h"
FRecord::FRecord() {
    Group = {};
    Sound = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Group"), (double)3);
}

FRecord::~FRecord() {
}
