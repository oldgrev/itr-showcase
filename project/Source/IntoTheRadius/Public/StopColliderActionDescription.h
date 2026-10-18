#pragma once

#include "CoreMinimal.h"
#include "RelevanceActionDescription.h"
#include "StopColliderActionDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UStopColliderActionDescription : public URelevanceActionDescription {
    GENERATED_BODY()
public:
    UStopColliderActionDescription(const FObjectInitializer& ObjectInitializer);

};
