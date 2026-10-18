#include "FalseTrueFloat.h"

#include "ITRDefaults.h"
FFalseTrueFloat::FFalseTrueFloat() {
    FalseValue = {};
    TrueValue = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("FalseValue"), (double)1);
    ITRDefaults::Set(StaticStruct(), this, TEXT("TrueValue"), (double)1);
}
