#pragma once

#include "CoreMinimal.h"
#include "MissionBaseHintObjectiveConfig.h"
#include "TagToItemConfigsList.h"
#include "MissionFindStashObjectiveConfig.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionFindStashObjectiveConfig : public UMissionBaseHintObjectiveConfig {
    GENERATED_BODY()
public:
    UMissionFindStashObjectiveConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FTagToItemConfigsList> PointsToStashes;
};
