#pragma once

#include "CoreMinimal.h"
#include "ShrapnelComponentApplyDamageDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FShrapnelComponentApplyDamage, const FVector&, Location, const bool, IsPearce);
