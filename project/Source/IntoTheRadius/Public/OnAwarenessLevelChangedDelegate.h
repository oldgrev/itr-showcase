#pragma once

#include "CoreMinimal.h"
#include "EAwarenessLevel.h"
#include "OnAwarenessLevelChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAwarenessLevelChanged, EAwarenessLevel, PrevLvl, EAwarenessLevel, NewLvl);
