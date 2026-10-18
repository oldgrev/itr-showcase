#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RelevanceCriteriaDescription.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API URelevanceCriteriaDescription : public UDataAsset {
    GENERATED_BODY()
public:
    URelevanceCriteriaDescription(const FObjectInitializer& ObjectInitializer);

};
