#pragma once

#include "CoreMinimal.h"
#include "RelevanceCriteriaDescription.h"
#include "EnemyDiscoverCriteriaDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UEnemyDiscoverCriteriaDescription : public URelevanceCriteriaDescription {
    GENERATED_BODY()
public:
    UEnemyDiscoverCriteriaDescription(const FObjectInitializer& ObjectInitializer);

};
