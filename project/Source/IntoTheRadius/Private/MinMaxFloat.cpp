#include "MinMaxFloat.h"

#include "ITRDefaults.h"
FMinMaxFloat::FMinMaxFloat() {
    Min = {};
    Max = {};
    ITRDefaults::Set(StaticStruct(), this, TEXT("Max"), (double)1);
}
