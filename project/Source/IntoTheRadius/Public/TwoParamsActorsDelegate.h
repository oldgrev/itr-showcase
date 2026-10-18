#pragma once

#include "CoreMinimal.h"
#include "TwoParamsActorsDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTwoParamsActors, AActor*, receiverActor, AActor*, itemActor);
