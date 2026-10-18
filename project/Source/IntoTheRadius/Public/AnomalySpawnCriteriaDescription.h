#pragma once

#include "CoreMinimal.h"
#include "RelevanceCriteriaDescription.h"
#include "AnomalySpawnCriteriaDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UAnomalySpawnCriteriaDescription : public URelevanceCriteriaDescription {
    GENERATED_BODY()
public:
    UAnomalySpawnCriteriaDescription(const FObjectInitializer& ObjectInitializer);

};
