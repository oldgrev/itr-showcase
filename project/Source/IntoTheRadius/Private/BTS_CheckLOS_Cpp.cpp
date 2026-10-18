#include "BTS_CheckLOS_Cpp.h"
#include "ITRDefaults.h"

UBTS_CheckLOS_Cpp::UBTS_CheckLOS_Cpp(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NodeName"), TEXT("Check LOS To Target"));
    ITRDefaults::SetNum(GetClass(), this, TEXT("BlackboardKey.AllowedTypes"), 0);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.SelectedKeyName"), TEXT("HasLOS"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("BlackboardKey.SelectedKeyType"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.SelectedKeyID"), (double)255);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.bNoneIsAllowedValue"), false);
}

