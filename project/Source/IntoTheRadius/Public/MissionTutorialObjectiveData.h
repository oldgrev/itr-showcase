#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MissionAbstractObjectiveData.h"
#include "MissionTutorialObjectiveData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionTutorialObjectiveData : public UMissionAbstractObjectiveData {
    GENERATED_BODY()
public:
    UMissionTutorialObjectiveData(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadOnly)
    FGameplayTag SequencerID;
    UPROPERTY(BlueprintReadOnly)
    FGameplayTag MapPoint;
    UPROPERTY(BlueprintReadOnly)
    TArray<FGameplayTag> ConfigTags;
};
