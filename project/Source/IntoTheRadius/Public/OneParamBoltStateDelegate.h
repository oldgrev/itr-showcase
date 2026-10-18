#pragma once

#include "CoreMinimal.h"
#include "EWeaponBoltState.h"
#include "OneParamBoltStateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneParamBoltState, EWeaponBoltState, prevState);
