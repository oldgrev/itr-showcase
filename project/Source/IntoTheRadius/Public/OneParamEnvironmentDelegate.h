#pragma once

#include "CoreMinimal.h"
#include "OneParamEnvironmentDelegate.generated.h"

class APREnvironment;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneParamEnvironment, const APREnvironment*, Environment);
