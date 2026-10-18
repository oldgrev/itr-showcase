#pragma once

#include "CoreMinimal.h"
#include "OnChangeHealthDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeHealth, float, HealthDelta);
