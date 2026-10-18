#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StringToTagsList.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FStringToTagsList {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Key;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTag> List;
    FStringToTagsList();
    ~FStringToTagsList();
};
