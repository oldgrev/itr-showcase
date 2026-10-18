#pragma once

#include "CoreMinimal.h"
#include "RelevanceActionDescription.h"
#include "ViewportNotifierDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UViewportNotifierDescription : public URelevanceActionDescription {
    GENERATED_BODY()
public:
    UViewportNotifierDescription(const FObjectInitializer& ObjectInitializer);

};
