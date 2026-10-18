#include "RecordSubtitle.h"

#include "ITRDefaults.h"
FRecordSubtitle::FRecordSubtitle() {
    Type = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("TimeFromTo.Max"), (double)1);
}

FRecordSubtitle::~FRecordSubtitle() {
}
