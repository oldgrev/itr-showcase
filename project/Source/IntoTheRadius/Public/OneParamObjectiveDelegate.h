#pragma once

#include "CoreMinimal.h"
#include "OneParamObjectiveDelegate.generated.h"

class UMissionAbstractObjectiveData;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneParamObjective, UMissionAbstractObjectiveData*, objectiveData);
