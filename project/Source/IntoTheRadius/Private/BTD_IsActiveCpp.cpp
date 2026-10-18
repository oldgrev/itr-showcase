#include "BTD_IsActiveCpp.h"
#include "ITRDefaults.h"

UBTD_IsActiveCpp::UBTD_IsActiveCpp(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NodeName"), TEXT("Is Active Cpp"));
    ITRDefaults::SetNum(GetClass(), this, TEXT("BlackboardKey.AllowedTypes"), 1);
    ITRDefaults::SetObject(GetClass(), this, TEXT("BlackboardKey.AllowedTypes[0]"), GetDefaultSubobjectByName(TEXT("BlackboardKey_Bool")));
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.SelectedKeyName"), TEXT("IsActive"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("BlackboardKey.SelectedKeyType"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.SelectedKeyID"), (double)255);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.bNoneIsAllowedValue"), false);
}

void UBTD_IsActiveCpp::OnNPCDied(AActor* DeadNPC) {
}

