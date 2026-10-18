#pragma once

#include "CoreMinimal.h"
#include "TwoParamsSleepDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTwoParamsSleep, float, Seconds, bool, isBlackout);
