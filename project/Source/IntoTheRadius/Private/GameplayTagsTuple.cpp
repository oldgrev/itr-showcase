#include "GameplayTagsTuple.h"

#include "ITRDefaults.h"
FGameplayTagsTuple::FGameplayTagsTuple() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("First.TagName"), TEXT("None"));
    ITRDefaults::Set(StaticStruct(), this, TEXT("Second.TagName"), TEXT("None"));
}
