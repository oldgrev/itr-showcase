#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsTuple.h"
#include "TagToTagTuplesList.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FTagToTagTuplesList {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag Tag;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTagsTuple> List;
    FTagToTagTuplesList();
};
