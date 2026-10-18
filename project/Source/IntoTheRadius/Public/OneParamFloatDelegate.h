#pragma once

#include "CoreMinimal.h"
#include "OneParamFloatDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneParamFloatDelegate, float, Value);
