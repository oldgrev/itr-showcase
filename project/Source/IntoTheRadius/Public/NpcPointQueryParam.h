#pragma once

#include "CoreMinimal.h"
#include "NpcPointQueryParam.generated.h"

class ACharacter;

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNpcPointQueryParam {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ACharacter* NpcCharacterRef;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector SearchCenter;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SearchRadius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector DesiredLocation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinDistanceToCenter;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDoPathLengthCheck;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxPathLength;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDoSquadDistanceCheck;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinSquadDistance;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxSearchIteration;
    UPROPERTY(EditAnywhere)
    bool bAlwaysMoveTowardsDesiredLocation;
    UPROPERTY(EditAnywhere)
    bool bUseDistantPointAsQueryCenter;
    UPROPERTY(EditAnywhere)
    bool bForceFastPointSearch;
    FNpcPointQueryParam();
};
