#pragma once

#include "CoreMinimal.h"
#include "TwoParamsActorVectorDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTwoParamsActorVector, AActor*, Actor, FVector, Value);
