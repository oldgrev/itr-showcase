#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ShrapnelComponentImpactDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FShrapnelComponentImpact, const FHitResult&, Hit, const float&, Scale);
