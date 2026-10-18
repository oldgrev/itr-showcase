#pragma once

#include "CoreMinimal.h"
#include "RelevanceActionDescription.h"
#include "StopParticleSystemsActionDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UStopParticleSystemsActionDescription : public URelevanceActionDescription {
    GENERATED_BODY()
public:
    UStopParticleSystemsActionDescription(const FObjectInitializer& ObjectInitializer);

};
