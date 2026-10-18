#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TagToItemConfig.generated.h"

class UPRItemConfig;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FTagToItemConfig {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag Tag;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
    UPRItemConfig* Config;
    FTagToItemConfig();
};
