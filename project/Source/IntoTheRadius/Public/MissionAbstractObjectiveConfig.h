#pragma once

#include "CoreMinimal.h"
#include "MissionAbstractObjectiveConfig.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew)
class INTOTHERADIUS_API UMissionAbstractObjectiveConfig : public UObject {
    GENERATED_BODY()
public:
    UMissionAbstractObjectiveConfig(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText ObjectiveShortName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText ObjectiveLongName;
};
