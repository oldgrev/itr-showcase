#pragma once

#include "CoreMinimal.h"
#include "MissionBaseObjectiveConfig.h"
#include "TagToTagsList.h"
#include "MissionTakePictureObjectiveConfig.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionTakePictureObjectiveConfig : public UMissionBaseObjectiveConfig {
    GENERATED_BODY()
public:
    UMissionTakePictureObjectiveConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FTagToTagsList> PointsToObjects;
};
