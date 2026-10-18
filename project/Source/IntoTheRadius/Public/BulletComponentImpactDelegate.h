#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "BulletComponentImpactDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBulletComponentImpact, const FHitResult&, Hit);
