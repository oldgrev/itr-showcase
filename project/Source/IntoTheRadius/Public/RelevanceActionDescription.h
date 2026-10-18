#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RelevanceActionDescription.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INTOTHERADIUS_API URelevanceActionDescription : public UDataAsset {
    GENERATED_BODY()
public:
    URelevanceActionDescription(const FObjectInitializer& ObjectInitializer);

};
