#pragma once

#include "CoreMinimal.h"
#include "MissionAbstractObjectiveConfig.h"
#include "MissionBaseObjectiveConfig.generated.h"

class UPRModifiableInt;

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionBaseObjectiveConfig : public UMissionAbstractObjectiveConfig {
    GENERATED_BODY()
public:
    UMissionBaseObjectiveConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    UPRModifiableInt* RewardMoneyOverride;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    UPRModifiableInt* RewardPlayerLevelOverride;
};
