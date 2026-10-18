#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "NpcPointQueryResult.h"
#include "CoverBTTask.generated.h"

class UBehaviorTreeComponent;

UCLASS(Blueprintable, BlueprintType)
class INTOTHERADIUS_API UCoverBTTask : public UBTTaskNode {
    GENERATED_BODY()
public:
    UCoverBTTask(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION()
    void OnQueryComplete(FNpcPointQueryResult Result);

public:
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector OutputVector;
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector TargetLocation;
    UPROPERTY(EditAnywhere)
    int32 MaxSearchIteration;
    UPROPERTY(EditAnywhere)
    float SearchRadius;
    UPROPERTY(EditAnywhere)
    float MinDistanceToTarget;
    UPROPERTY(EditAnywhere)
    bool bDoPathLengthCheck;
    UPROPERTY(EditAnywhere)
    float MaxPathLength;
    UPROPERTY(EditAnywhere)
    bool bDoSquadDistanceCheck;
    UPROPERTY(EditAnywhere)
    float MinSquadDistance;
    UPROPERTY(EditAnywhere)
    bool bAlwaysMoveTowardsDesiredLocation;
    UPROPERTY(EditAnywhere)
    bool bUseDistantPointAsQueryCenter;
    UPROPERTY(EditAnywhere)
    bool bForceFastPointSearch;
private:
    UPROPERTY()
    UBehaviorTreeComponent* BehaviorTreeComponent;
};
