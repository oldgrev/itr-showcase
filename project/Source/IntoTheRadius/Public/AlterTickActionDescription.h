#pragma once

#include "CoreMinimal.h"
#include "RelevanceActionDescription.h"
#include "AlterTickActionDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UAlterTickActionDescription : public URelevanceActionDescription {
    GENERATED_BODY()
public:
    UAlterTickActionDescription(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool StopTick;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TickIntervalMultiplier;
};
