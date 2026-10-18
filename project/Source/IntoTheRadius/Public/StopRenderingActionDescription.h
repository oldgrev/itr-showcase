#pragma once

#include "CoreMinimal.h"
#include "RelevanceActionDescription.h"
#include "StopRenderingActionDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UStopRenderingActionDescription : public URelevanceActionDescription {
    GENERATED_BODY()
public:
    UStopRenderingActionDescription(const FObjectInitializer& ObjectInitializer);

};
