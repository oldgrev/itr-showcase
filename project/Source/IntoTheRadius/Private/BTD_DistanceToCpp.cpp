#include "BTD_DistanceToCpp.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "ITRDefaults.h"

UBTD_DistanceToCpp::UBTD_DistanceToCpp(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    UBlackboardKeyType_Object* Sub0 = Cast<UBlackboardKeyType_Object>(GetDefaultSubobjectByName(TEXT("BlackboardKey_Object_2147482634")));
    if (!Sub0) Sub0 = CreateDefaultSubobject<UBlackboardKeyType_Object>(TEXT("BlackboardKey_Object_2147482634"));
    if (UObject* S = GetDefaultSubobjectByName(TEXT("BlackboardKey_Object_2147482634"))) {
        ITRDefaults::Set(S->GetClass(), S, TEXT("BaseClass"), TEXT("/Script/Engine.Actor"));
    }
    ITRDefaults::Set(GetClass(), this, TEXT("NodeName"), TEXT("Distance To Cpp"));
    ITRDefaults::SetNum(GetClass(), this, TEXT("BlackboardKey.AllowedTypes"), 2);
    ITRDefaults::SetObject(GetClass(), this, TEXT("BlackboardKey.AllowedTypes[0]"), GetDefaultSubobjectByName(TEXT("BlackboardKey_Object_2147482634")));
    ITRDefaults::SetObject(GetClass(), this, TEXT("BlackboardKey.AllowedTypes[1]"), GetDefaultSubobjectByName(TEXT("BlackboardKey_Vector")));
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.SelectedKeyName"), TEXT("None"));
    ITRDefaults::SetObject(GetClass(), this, TEXT("BlackboardKey.SelectedKeyType"), nullptr);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.SelectedKeyID"), (double)255);
    ITRDefaults::Set(GetClass(), this, TEXT("BlackboardKey.bNoneIsAllowedValue"), false);
    ITRDefaults::Set(GetClass(), this, TEXT("RefreshInterval"), (double)1);
}

