#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TagToItemConfigsList.generated.h"

class UPRItemConfig;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FTagToItemConfigsList {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag Tag;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    TArray<UPRItemConfig*> Configs;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomUID;
    FTagToItemConfigsList();
    ~FTagToItemConfigsList();
};
