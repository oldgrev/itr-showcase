#pragma once

#include "CoreMinimal.h"
#include "BulletComponentApplyDamageDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBulletComponentApplyDamage, const FVector&, Location, const bool, IsPearce);
