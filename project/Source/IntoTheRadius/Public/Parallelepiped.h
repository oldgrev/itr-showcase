#pragma once

#include "CoreMinimal.h"
#include "Parallelepiped.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FParallelepiped {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform Center;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Extent;
    FParallelepiped();
};
