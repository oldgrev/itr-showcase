#pragma once

#include "CoreMinimal.h"
#include "MissionBaseObjectiveConfig.h"
#include "MissionDestroyGeneratorsObjectiveConfig.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionDestroyGeneratorsObjectiveConfig : public UMissionBaseObjectiveConfig {
    GENERATED_BODY()
public:
    UMissionDestroyGeneratorsObjectiveConfig(const FObjectInitializer& ObjectInitializer);

};
