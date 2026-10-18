#pragma once

#include "CoreMinimal.h"
#include "TwoParamsIntAndStringArrayDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTwoParamsIntAndStringArray, int32, Value, const TArray<FString>&, AnalyticsParams);
