#pragma once

#include "CoreMinimal.h"
#include "MissionBaseObjectiveConfig.h"
#include "TagToTagsList.h"
#include "MissionKillNPCObjectiveConfig.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionKillNPCObjectiveConfig : public UMissionBaseObjectiveConfig {
    GENERATED_BODY()
public:
    UMissionKillNPCObjectiveConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FTagToTagsList> PointsToNPCs;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpawnNPCsRadius;
};
