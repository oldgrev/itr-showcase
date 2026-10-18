#include "BTD_BlackboardBool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "ITRDefaults.h"

UBTD_BlackboardBool::UBTD_BlackboardBool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UBlackboardKeyType_Bool* Sub0 = Cast<UBlackboardKeyType_Bool>(GetDefaultSubobjectByName(TEXT("BlackboardKey_Bool")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UBlackboardKeyType_Bool>(TEXT("BlackboardKey_Bool"));
    ITRDefaults::Set(GetClass(), this, TEXT("NodeName"), TEXT("Blackboard Bool"));
    ITRDefaults::SetNum(GetClass(), this, TEXT("BlackboardKey.AllowedTypes"), 1);
    ITRDefaults::SetObject(GetClass(), this, TEXT("BlackboardKey.AllowedTypes[0]"), GetDefaultSubobjectByName(TEXT("BlackboardKey_Bool")));
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.SelectedKeyName"), TEXT("None"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("BlackboardKey.SelectedKeyType"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.SelectedKeyID"), (double)255);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.bNoneIsAllowedValue"), false);
}

