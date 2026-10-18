#include "CloseCombatManagerTickFunction.h"

#include "ITRDefaults.h"
FCloseCombatManagerTickFunction::FCloseCombatManagerTickFunction() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("TickGroup"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("EndTickGroup"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("bTickEvenWhenPaused"), false);
    ITRDefaults::Set(StaticStruct(), this, TEXT("bCanEverTick"), false);
    ITRDefaults::Set(StaticStruct(), this, TEXT("bStartWithTickEnabled"), false);
    ITRDefaults::Set(StaticStruct(), this, TEXT("bAllowTickOnDedicatedServer"), true);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TickInterval"), (double)0);
}
