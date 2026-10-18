#include "BTT_Bot_StartAttackCpp.h"
#include "ITRDefaults.h"

UBTT_Bot_StartAttackCpp::UBTT_Bot_StartAttackCpp(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    ITRDefaults::Set(GetClass(), this, TEXT("NodeName"), TEXT("Bot Start Attack"));
}

