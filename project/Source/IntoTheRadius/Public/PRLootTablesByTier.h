#pragma once

#include "CoreMinimal.h"
#include "PRLootTableConfig.h"
#include "PRLootTablesByTier.generated.h"

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FPRLootTablesByTier {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool RandomizePassedTier;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<int32, FPRLootTableConfig> Tiers;
    FPRLootTablesByTier();
};
