#pragma once

#include "CoreMinimal.h"
#include "RelevanceActionDescription.h"
#include "DiscoverEnemyActionDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UDiscoverEnemyActionDescription : public URelevanceActionDescription {
    GENERATED_BODY()
public:
    UDiscoverEnemyActionDescription(const FObjectInitializer& ObjectInitializer);

};
