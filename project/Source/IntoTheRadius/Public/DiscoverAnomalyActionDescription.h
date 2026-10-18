#pragma once

#include "CoreMinimal.h"
#include "RelevanceActionDescription.h"
#include "DiscoverAnomalyActionDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UDiscoverAnomalyActionDescription : public URelevanceActionDescription {
    GENERATED_BODY()
public:
    UDiscoverAnomalyActionDescription(const FObjectInitializer& ObjectInitializer);

};
