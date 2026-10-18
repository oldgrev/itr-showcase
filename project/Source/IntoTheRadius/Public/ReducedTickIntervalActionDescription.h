#pragma once

#include "CoreMinimal.h"
#include "RelevanceActionDescription.h"
#include "ReducedTickIntervalActionDescription.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UReducedTickIntervalActionDescription : public URelevanceActionDescription {
    GENERATED_BODY()
public:
    UReducedTickIntervalActionDescription(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ActorTickIntervalMultiplier;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AnimationTickIntervalMultiplier;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PerceptionTickIntervalMultiplier;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MovementTickIntervalMultiplier;
};
