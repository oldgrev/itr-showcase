#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TwoParamsActorGTagDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTwoParamsActorGTag, AActor*, Actor, FGameplayTag, Tag);
