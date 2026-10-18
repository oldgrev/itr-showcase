#include "SaveInfo.h"

FSaveInfo::FSaveInfo() {
    SaveNr = {};
    Autosave = {};
    Ironman = {};
    DateTime = FDateTime(0);
    TimeSpentMinutes = {};
    Money = {};
}

FSaveInfo::~FSaveInfo() {
}
