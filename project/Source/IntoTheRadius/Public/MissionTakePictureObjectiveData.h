#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MissionAbstractObjectiveData.h"
#include "MissionRecord.h"
#include "TagToTagsList.h"
#include "MissionTakePictureObjectiveData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionTakePictureObjectiveData : public UMissionAbstractObjectiveData {
    GENERATED_BODY()
public:
    UMissionTakePictureObjectiveData(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintPure)
    TArray<FGameplayTag> GetObjectsTags();

    UPROPERTY(BlueprintReadOnly)
    TArray<FTagToTagsList> PointsToObjects;
    UPROPERTY(BlueprintReadOnly)
    TArray<FMissionRecord> CollectedPhotos;
};
