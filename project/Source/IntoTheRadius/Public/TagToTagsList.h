#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TagToTagsList.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FTagToTagsList {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag Tag;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTag> List;
    FTagToTagsList();
    ~FTagToTagsList();
};
