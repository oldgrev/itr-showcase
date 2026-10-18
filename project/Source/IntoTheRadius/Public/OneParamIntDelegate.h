#pragma once

#include "CoreMinimal.h"
#include "OneParamIntDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneParamInt, const int32, Value);
