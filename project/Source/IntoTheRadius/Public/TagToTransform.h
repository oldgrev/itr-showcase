#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TagToTransform.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FTagToTransform {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag Tag;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform Transform;
    FTagToTransform();
};
