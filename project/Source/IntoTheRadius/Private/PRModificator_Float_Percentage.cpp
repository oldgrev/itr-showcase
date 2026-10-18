#include "PRModificator_Float_Percentage.h"
#include "ITRDefaults.h"

UPRModificator_Float_Percentage::UPRModificator_Float_Percentage(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("Percentage"), (double)100);
}

