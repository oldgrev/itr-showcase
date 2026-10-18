#pragma once

#include "CoreMinimal.h"
#include "RelevanceCriteriaDescription.h"
#include "PlayerViewportCriteriaDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPlayerViewportCriteriaDescription : public URelevanceCriteriaDescription {
    GENERATED_BODY()
public:
    UPlayerViewportCriteriaDescription(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool CheckBoundingBox;
};
