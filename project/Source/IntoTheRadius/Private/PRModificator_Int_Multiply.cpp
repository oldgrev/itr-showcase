#include "PRModificator_Int_Multiply.h"
#include "ITRDefaults.h"

UPRModificator_Int_Multiply::UPRModificator_Int_Multiply(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("MultiplyBy"), (double)1);
}

