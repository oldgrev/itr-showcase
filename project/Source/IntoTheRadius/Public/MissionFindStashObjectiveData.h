#pragma once

#include "CoreMinimal.h"
#include "MissionAbstractObjectiveData.h"
#include "TagToItemConfigsList.h"
#include "MissionFindStashObjectiveData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionFindStashObjectiveData : public UMissionAbstractObjectiveData {
    GENERATED_BODY()
public:
    UMissionFindStashObjectiveData(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadOnly)
    TArray<FTagToItemConfigsList> PointsToStashes;
};
