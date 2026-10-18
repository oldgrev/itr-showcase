#pragma once

#include "CoreMinimal.h"
#include "MissionBaseObjectiveConfig.h"
#include "TagToItemConfigsList.h"
#include "TagToTagsList.h"
#include "MissionFetchItemsObjectiveConfig.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionFetchItemsObjectiveConfig : public UMissionBaseObjectiveConfig {
    GENERATED_BODY()
public:
    UMissionFetchItemsObjectiveConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FTagToTagsList> PointsToDefaultItems;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FTagToItemConfigsList> PointsToConfigItems;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool SpawnItems;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool CleanItems;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpawnRadiusForOnePoint;
};
