#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TagToTransformsList.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FTagToTransformsList {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FGameplayTag, FTransform> List;
    FTagToTransformsList();
    ~FTagToTransformsList();
};
