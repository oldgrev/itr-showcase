#pragma once

#include "CoreMinimal.h"
#include "RelevanceCriteriaDescription.h"
#include "AnomalyDiscoverCriteriaDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UAnomalyDiscoverCriteriaDescription : public URelevanceCriteriaDescription {
    GENERATED_BODY()
public:
    UAnomalyDiscoverCriteriaDescription(const FObjectInitializer& ObjectInitializer);

};
