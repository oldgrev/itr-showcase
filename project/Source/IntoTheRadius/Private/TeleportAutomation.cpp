#include "TeleportAutomation.h"
#include "ITRDefaults.h"

UTeleportAutomation::UTeleportAutomation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("TeleportDelayInSec"), (double)10);
}

void UTeleportAutomation::LevelReadyCallback() {
}

