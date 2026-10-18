#pragma once

#include "CoreMinimal.h"
#include "RelevanceActionDescription.h"
#include "PlayFootstepsDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UPlayFootstepsDescription : public URelevanceActionDescription {
    GENERATED_BODY()
public:
    UPlayFootstepsDescription(const FObjectInitializer& ObjectInitializer);

};
