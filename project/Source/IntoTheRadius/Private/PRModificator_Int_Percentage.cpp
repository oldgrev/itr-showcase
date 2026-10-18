#include "PRModificator_Int_Percentage.h"
#include "ITRDefaults.h"

UPRModificator_Int_Percentage::UPRModificator_Int_Percentage(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("Percentage"), (double)100);
}

