#pragma once

#include "CoreMinimal.h"
#include "OneParamMissionDelegate.generated.h"

class UMissionData;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneParamMission, UMissionData*, MissionData);
