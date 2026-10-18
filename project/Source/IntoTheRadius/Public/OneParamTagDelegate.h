#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OneParamTagDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneParamTag, FGameplayTag, Value);
