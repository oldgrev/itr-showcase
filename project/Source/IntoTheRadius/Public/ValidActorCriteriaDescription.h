#pragma once

#include "CoreMinimal.h"
#include "RelevanceCriteriaDescription.h"
#include "ValidActorCriteriaDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UValidActorCriteriaDescription : public URelevanceCriteriaDescription {
    GENERATED_BODY()
public:
    UValidActorCriteriaDescription(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAlwaysOffForPC;
};
