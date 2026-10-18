#include "BTT_Bot_StopAttackCpp.h"
#include "ITRDefaults.h"

UBTT_Bot_StopAttackCpp::UBTT_Bot_StopAttackCpp(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NodeName"), TEXT("Bot Stop Attack"));
}

