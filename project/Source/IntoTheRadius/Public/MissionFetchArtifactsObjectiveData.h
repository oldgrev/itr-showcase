#pragma once

#include "CoreMinimal.h"
#include "MissionAbstractObjectiveData.h"
#include "MissionFetchArtifactsObjectiveData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UMissionFetchArtifactsObjectiveData : public UMissionAbstractObjectiveData {
    GENERATED_BODY()
public:
    UMissionFetchArtifactsObjectiveData(const FObjectInitializer& ObjectInitializer);

};
