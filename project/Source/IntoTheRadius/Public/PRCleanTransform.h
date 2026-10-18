#pragma once

#include "CoreMinimal.h"
#include "PRCleanTransform.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FPRCleanTransform {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector Location;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVector Rotation;
    FPRCleanTransform();
};
