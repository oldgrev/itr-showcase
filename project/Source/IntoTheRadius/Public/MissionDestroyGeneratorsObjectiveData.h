#pragma once

#include "CoreMinimal.h"
#include "MissionAbstractObjectiveData.h"
#include "MissionDestroyGeneratorsObjectiveData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionDestroyGeneratorsObjectiveData : public UMissionAbstractObjectiveData {
    GENERATED_BODY()
public:
    UMissionDestroyGeneratorsObjectiveData(const FObjectInitializer& ObjectInitializer);

};
