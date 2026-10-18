#pragma once

#include "CoreMinimal.h"
#include "TwoParamsMissionAndObjectiveDelegate.generated.h"

class UMissionAbstractObjectiveData;
class UMissionData;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTwoParamsMissionAndObjective, UMissionData*, MissionData, UMissionAbstractObjectiveData*, objectiveData);
