#include "ShutdownAutomation.h"
#include "ITRDefaults.h"

UShutdownAutomation::UShutdownAutomation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("ShutdownDelayInSec"), (double)10);
}

