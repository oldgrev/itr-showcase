#pragma once

#include "CoreMinimal.h"
#include "MissionBaseConfig.h"
#include "MissionTutorialConfig.generated.h"

class UMissionTutorialObjectiveConfig;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionTutorialConfig : public UMissionBaseConfig {
    GENERATED_BODY()
public:
    UMissionTutorialConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AutoProgress;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    UMissionTutorialObjectiveConfig* TutorialObjective;
};
