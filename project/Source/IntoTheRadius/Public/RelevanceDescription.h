#pragma once

#include "CoreMinimal.h"
#include "RelevanceDescription.generated.h"

class URelevanceActionDescription;
class URelevanceCriteriaDescription;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FRelevanceDescription {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    URelevanceCriteriaDescription* Criteria;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<URelevanceActionDescription*> Actions;
    FRelevanceDescription();
    ~FRelevanceDescription();
};
