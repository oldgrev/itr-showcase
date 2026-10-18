#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MissionBaseHintObjectiveConfig.h"
#include "MissionInfoObjectiveConfig.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionInfoObjectiveConfig : public UMissionBaseHintObjectiveConfig {
    GENERATED_BODY()
public:
    UMissionInfoObjectiveConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTag> Points;
};
