#include "DialoguesGroup.h"

#include "ITRDefaults.h"
FDialoguesGroup::FDialoguesGroup() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("GroupID.TagName"), TEXT("None"));
}

FDialoguesGroup::~FDialoguesGroup() {
}
