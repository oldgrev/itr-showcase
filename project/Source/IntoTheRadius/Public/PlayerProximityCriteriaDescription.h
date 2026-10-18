#pragma once

#include "CoreMinimal.h"
#include "RelevanceCriteriaDescription.h"
#include "PlayerProximityCriteriaDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPlayerProximityCriteriaDescription : public URelevanceCriteriaDescription {
    GENERATED_BODY()
public:
    UPlayerProximityCriteriaDescription(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayerDistancePC;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayerDistanceQuest;
};
