#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MissionBaseObjectiveConfig.h"
#include "MissionTutorialObjectiveConfig.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionTutorialObjectiveConfig : public UMissionBaseObjectiveConfig {
    GENERATED_BODY()
public:
    UMissionTutorialObjectiveConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag SequencerID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag MapPoint;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTag> ConfigTags;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ApplyReward;
};
