#pragma once

#include "CoreMinimal.h"
#include "RelevanceActionDescription.h"
#include "DeactivateRootActionDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UDeactivateRootActionDescription : public URelevanceActionDescription {
    GENERATED_BODY()
public:
    UDeactivateRootActionDescription(const FObjectInitializer& ObjectInitializer);

};
