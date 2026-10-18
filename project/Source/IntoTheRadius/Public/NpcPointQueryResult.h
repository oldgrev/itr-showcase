#pragma once

#include "CoreMinimal.h"
#include "NpcPointQueryResult.generated.h"

USTRUCT(BlueprintType)
struct INTOTHERADIUS_API FNpcPointQueryResult {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPointFound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Point;
    FNpcPointQueryResult();
    ~FNpcPointQueryResult();
};
