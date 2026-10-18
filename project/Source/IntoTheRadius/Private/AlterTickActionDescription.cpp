#include "AlterTickActionDescription.h"
#include "ITRDefaults.h"

UAlterTickActionDescription::UAlterTickActionDescription(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NativeClass"), TEXT("/Script/IntoTheRadius.AlterTickActionDescription"));
}

