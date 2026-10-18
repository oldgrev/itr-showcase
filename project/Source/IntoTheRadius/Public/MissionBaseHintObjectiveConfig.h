#pragma once

#include "CoreMinimal.h"
#include "MissionAbstractObjectiveConfig.h"
#include "MissionBaseHintObjectiveConfig.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionBaseHintObjectiveConfig : public UMissionAbstractObjectiveConfig {
    GENERATED_BODY()
public:
    UMissionBaseHintObjectiveConfig(const FObjectInitializer& ObjectInitializer);

};
