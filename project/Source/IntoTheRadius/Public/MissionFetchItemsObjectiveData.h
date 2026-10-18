#pragma once

#include "CoreMinimal.h"
#include "MissionAbstractObjectiveData.h"
#include "MissionRecord.h"
#include "TagToItemConfigsList.h"
#include "TagToTagsList.h"
#include "MissionFetchItemsObjectiveData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionFetchItemsObjectiveData : public UMissionAbstractObjectiveData {
    GENERATED_BODY()
public:
    UMissionFetchItemsObjectiveData(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadOnly)
    TArray<FTagToTagsList> PointsToDefaultItems;
    UPROPERTY(BlueprintReadOnly)
    TArray<FTagToItemConfigsList> PointsToConfigItems;
    UPROPERTY(BlueprintReadOnly)
    TArray<FMissionRecord> CollectedItems;
    UPROPERTY(BlueprintReadOnly)
    bool SpawnItems;
    UPROPERTY(BlueprintReadOnly)
    bool CleanItems;
    UPROPERTY(BlueprintReadOnly)
    float SpawnRadiusForOnePoint;
};
