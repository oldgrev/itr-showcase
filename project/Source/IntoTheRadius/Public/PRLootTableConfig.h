#pragma once

#include "CoreMinimal.h"
#include "PRLootTableConfig.generated.h"

class UDataTable;
class UPRCondition;

USTRUCT(BlueprintType, Atomic)
struct INTOTHERADIUS_API FPRLootTableConfig {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced)
    TArray<UPRCondition*> Conditions;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 LootPoints;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UDataTable* LootTable;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool ExcludeGeneration;
    FPRLootTableConfig();
    ~FPRLootTableConfig();
};
