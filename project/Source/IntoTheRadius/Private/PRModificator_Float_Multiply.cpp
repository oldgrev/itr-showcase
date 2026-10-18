#include "PRModificator_Float_Multiply.h"
#include "ITRDefaults.h"

UPRModificator_Float_Multiply::UPRModificator_Float_Multiply(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("MultiplyBy"), (double)1);
}

