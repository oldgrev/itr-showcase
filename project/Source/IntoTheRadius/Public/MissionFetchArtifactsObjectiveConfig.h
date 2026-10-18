#pragma once

#include "CoreMinimal.h"
#include "MissionBaseObjectiveConfig.h"
#include "MissionFetchArtifactsObjectiveConfig.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionFetchArtifactsObjectiveConfig : public UMissionBaseObjectiveConfig {
    GENERATED_BODY()
public:
    UMissionFetchArtifactsObjectiveConfig(const FObjectInitializer& ObjectInitializer);

};
