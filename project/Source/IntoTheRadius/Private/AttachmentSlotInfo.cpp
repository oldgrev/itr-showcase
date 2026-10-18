#include "AttachmentSlotInfo.h"

#include "ITRDefaults.h"
FAttachmentSlotInfo::FAttachmentSlotInfo() {
    Icon = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("TypeID.TagName"), TEXT("None"));
}

FAttachmentSlotInfo::~FAttachmentSlotInfo() {
}
