#pragma once

#include "CoreMinimal.h"
#include "BulletComponentRicochetDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FBulletComponentRicochet, const FVector&, Location, const FVector&, Force, const bool, IsPenetration);
